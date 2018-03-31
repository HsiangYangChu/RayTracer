#include <mpi.h>
#include <scheduler.h>
#include <world.h>
#include <texture.h>
#include <camera.h>
#include <vector>

Scheduler::Scheduler(int argc, char **argv, const World *w):
  world(w)
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
}

Scheduler::~Scheduler()
{
    MPI_Finalize();
}

int Scheduler::getRank()
{
    int rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    return rank;
}

void Scheduler::performTask(const char *filename)
{
    if (size == 1)
    {
        world->renderScene(filename);
        return;
    }

    int rank = getRank();

    if (!world->camera->is_built)
    {
        world->camera->build();
    }

    Texture_ptr texture;
    RGBQUAD *texture_bits = NULL;
    RgbQuads pixels;
    std::vector<int> recvcounts(size, 0), displs(size, 0);

    WorkArea wa;

    for (int i = 1; i < size; i++)
    {
        getWorkArea(i, wa);

        recvcounts[i] = wa.end - wa.start;
        displs[i] = wa.start;
    }

    if (rank == 0)
    {
        const ViewPlane &vp = world->vp;
        texture = Texture::create(vp.hres, vp.vres);
        texture_bits = (RGBQUAD*)texture->getBits();
    }
    else
    {
        performRenderTask(rank, pixels);
    }

    MPI_Gatherv(pixels.data(), pixels.size(), MPI_UINT32_T, texture_bits, recvcounts.data(),
                displs.data(), MPI_UINT32_T, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        texture->save(filename, FIF_BMP);
    }
}

void Scheduler::getWorkArea(int rank, WorkArea &wa)
{
    const ViewPlane &vp = world->vp;

    uint N = vp.hres * vp.vres;

    wa.start = N / (size - 1) * (rank - 1);
    wa.end = (rank == size - 1) ? N : N / (size - 1) * (rank);
}

void Scheduler::performRenderTask(int rank, RgbQuads &pixels)
{
    WorkArea wa;

    const ViewPlane &vp = world->vp;

    getWorkArea(rank, wa);

    uint w = wa.end - wa.start;

    pixels.resize(w);

    for (uint i = 0; i < w; i++)
    {
        uint y = (i + wa.start) / vp.hres;
        uint x = (i + wa.start) % vp.hres;

        pixels[i] = Texture::toRgbQuad(world->renderPixel(x, y));
    }
}
