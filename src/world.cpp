#include <mpi.h>
#include <world.h>
#include <ray.h>
#include <tracers/tracers.h>
#include <objects/objects.h>
#include <iostream>
#include <samplers/samplers.h>
#include <cameras/cameras.h>
#include <lights/lights.h>
#include <materials/materials.h>
#include <backgrounds/backgrounds.h>
#include <scheduler.h>
#include <scene_parser.h>

World::World()
{
}

World::~World()
{
}

World &World::getInstance()
{
    static World w;

    return w;
}

void World::build(const char *filename)
{
    SceneParser scene_parser(filename);
    scene_parser.build();
}

void World::renderScene(const char *filename) const
{
    camera->renderScene()->save(filename, FIF_BMP);
}

void World::renderSceneWithMpi(int argc, char **argv, const char *filename)
{
    Scheduler render_scheduler(argc, argv, this);
    render_scheduler.performTask(filename);
}

void World::displayPixel(uint c, uint r, const Color &pixel_color, Texture_ptr &texture) const
{
    texture->set(c, r, pixel_color);
}

void World::addObject(const Object_ptr &o)
{
    objects.push_back(o);
}

void World::addLight(const Light_ptr &l)
{
    lights.push_back(l);
}

Intersection World::hitObjects(const Ray &ray) const
{
    Intersection is_min(*this);

    for (uint i = 0; i < objects.size(); i++)
    {
        Intersection is(*this);

        if (objects[i]->hit(ray, is) && is < is_min)
        {
            is.hit_an_object = true;
            is.hit_point = ray.o + is.t * ray.d;
            is.material = objects[i]->getMaterial().get();

            is_min = is;
        }
    }

    return is_min;
}

void World::setAmbient(const Light_ptr &light)
{
    ambient = light;
}

void World::setBackground(const Background_ptr &l_background)
{
    background = l_background;
}

Color World::renderPixel(uint w, uint h) const
{
    return camera->renderPixel(w, h);
}
