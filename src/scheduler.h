#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <memory>
#include <mymath.h>
#include <vector>
#include <texture.h>

class World;

struct WorkArea
{
    uint start;
    uint end;
};

class Scheduler
{
public:
    typedef std::shared_ptr<Texture> Texture_ptr;
    typedef std::vector<RGBQUAD> RgbQuads;

    Scheduler(int, char **, const World *);
    ~Scheduler();

    void performTask(const char *);

private:

    void performRenderTask(int, RgbQuads &);
    int getRank();
    void getWorkArea(int, WorkArea &);

    const World *world;
    int size;
};

#endif
