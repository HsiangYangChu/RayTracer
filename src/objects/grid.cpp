#include <objects/grid.h>
#include <intersection.h>

Grid::Grid(const std::string &name): Compound(name), n(1)
{
}

void Grid::setupCells()
{
    cells.clear();

    vec3 w = bbox.p1 - bbox.p0;

    FLOAT m = 2.0;

    FLOAT s = glm::pow(glm::compMul(w) / objects.size(), 0.3333333);

    n = m / s * w + vec3(1);

    uint size = glm::compMul(n);

    for (uint i = 0; i < size; i++)
    {
        cells.push_back(Compound_ptr());
    }

    for (uint i = 0; i < objects.size(); i++)
    {
        BBox obj_bbox = objects[i]->getBBox();

        CellIndex start = getCellIndexByLocation(obj_bbox.p0);
        CellIndex end = getCellIndexByLocation(obj_bbox.p1);

        for (uint xi = uint(start.x); xi <= uint(end.x); xi++)
        {
            for (uint yi = uint(start.y); yi <= uint(end.y); yi++)
            {
                for (uint zi = uint(start.z); zi <= uint(end.z); zi++)
                {
                    Compound_ptr &ptr = getCell(xi, yi, zi);

                    if (!ptr)
                    {
                        Compound *compound = new Compound;
                        compound->addObject(objects[i]);
                        ptr.reset(compound);
                    }
                    else
                    {
                        ptr->addObject(objects[i]);
                    }
                }
            }
        }
    }
}

Grid::CellIndex Grid::getCellIndexByLocation(const vec3 &v) const
{
    return CellIndex(glm::clamp((v - bbox.p0) / (bbox.p1 - bbox.p0) * vec3(n),
                     vec3(0), vec3(n) - vec3(1)));
}

bool Grid::hit(const Ray &ray, Intersection &is) const
{
    FLOAT t_in;
    vec3 tmin, tmax;

    if (!bbox.hit(ray, t_in, tmin, tmax))
    {
        return false;
    }

    vec3 p = (bbox.isInside(ray.o)) ? (ray.o) : (ray.o + t_in * ray.d);
    CellIndex idx = getCellIndexByLocation(p);

    vec3 dt = vec3(tmax - tmin) / vec3(n);

    vec3 t_next;
    CellIndex idx_step, idx_stop;

    for (uint i = 0; i < 3; i++)
    {
        if (ray.d[i] > 0)
        {
            t_next[i] = tmin[i] + (idx[i] + 1) * dt[i];
            idx_step[i] = 1;
            idx_stop[i] = n[i];
        }
        else if (ray.d[i] < 0)
        {
            t_next[i] = tmin[i] + (n[i] - idx[i]) * dt[i];
            idx_step[i] = -1;
            idx_stop[i] = -1;
        }
        else
        {
            t_next[i] = INFINITY;
            idx_step[i] = -1;
            idx_stop[i] = -1;
        }
    }

    while (true)
    {
        const Compound_ptr &compound = getCell(idx.x, idx.y, idx.z);

        if (t_next.x < t_next.y && t_next.x < t_next.z)
        {
            if (compound && compound->hit(ray, is) && is.t < t_next.x)
            {
                material = compound->getMaterial();
                return true;
            }

            t_next.x += dt.x;
            idx.x += idx_step.x;

            if (idx.x == idx_stop.x)
            {
                return false;
            }
        }
        else
        {
            if (t_next.y < t_next.z)
            {
                if (compound && compound->hit(ray, is) && is.t < t_next.y)
                {
                    material = compound->getMaterial();
                    return true;
                }

                t_next.y += dt.y;
                idx.y += idx_step.y;

                if (idx.y == idx_stop.y)
                {
                    return false;
                }
            }
            else
            {
                if (compound && compound->hit(ray, is) && is.t < t_next.z)
                {
                    material = compound->getMaterial();
                    return true;
                }

                t_next.z += dt.z;
                idx.z += idx_step.z;

                if (idx.z == idx_stop.z)
                {
                    return false;
                }
            }
        }
    }
}

Grid::Compound_ptr &Grid::getCell(uint x, uint y, uint z)
{
    return cells[x * n.y * n.z + y * n.z + z];
}

const Grid::Compound_ptr &Grid::getCell(uint x, uint y, uint z) const
{
    return cells[x * n.y * n.z + y * n.z + z];
}

bool Grid::shadowHit(const Ray &ray, FLOAT &shadow_tmin) const
{
    FLOAT t_in;
    vec3 tmin, tmax;

    if (!bbox.hit(ray, t_in, tmin, tmax))
    {
        return false;
    }

    vec3 p = (bbox.isInside(ray.o)) ? (ray.o) : (ray.o + t_in * ray.d);
    CellIndex idx = getCellIndexByLocation(p);

    vec3 dt = vec3(tmax - tmin) / vec3(n);

    vec3 t_next;
    CellIndex idx_step, idx_stop;

    for (uint i = 0; i < 3; i++)
    {
        if (ray.d[i] > 0)
        {
            t_next[i] = tmin[i] + (idx[i] + 1) * dt[i];
            idx_step[i] = 1;
            idx_stop[i] = n[i];
        }
        else if (ray.d[i] < 0)
        {
            t_next[i] = tmin[i] + (n[i] - idx[i]) * dt[i];
            idx_step[i] = -1;
            idx_stop[i] = -1;
        }
        else
        {
            t_next[i] = INFINITY;
            idx_step[i] = -1;
            idx_stop[i] = -1;
        }
    }

    FLOAT t;

    while (true)
    {
        const Compound_ptr &compound = getCell(idx.x, idx.y, idx.z);

        if (t_next.x < t_next.y && t_next.x < t_next.z)
        {
            if (compound && compound->shadowHit(ray, t) && t < t_next.x)
            {
                shadow_tmin = t;
                return true;
            }

            t_next.x += dt.x;
            idx.x += idx_step.x;

            if (idx.x == idx_stop.x)
            {
                return false;
            }
        }
        else
        {
            if (t_next.y < t_next.z)
            {
                if (compound && compound->shadowHit(ray, t) && t < t_next.y)
                {
                    shadow_tmin = t;
                    return true;
                }

                t_next.y += dt.y;
                idx.y += idx_step.y;

                if (idx.y == idx_stop.y)
                {
                    return false;
                }
            }
            else
            {
                if (compound && compound->shadowHit(ray, t) && t < t_next.z)
                {
                    shadow_tmin = t;
                    return true;
                }

                t_next.z += dt.z;
                idx.z += idx_step.z;

                if (idx.z == idx_stop.z)
                {
                    return false;
                }
            }
        }
    }
}
