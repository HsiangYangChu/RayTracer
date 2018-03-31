#ifndef WORLD_H
#define WORLD_H

#include <mymath.h>
#include <texture.h>
#include <memory>
#include <viewplane.h>
#include <intersection.h>
#include <vector>

struct Camera;
class Tracer;
class Light;
class Object;
class Ray;
class Background;
class Material;

class World
{
public:
    typedef std::shared_ptr<Camera> Camera_ptr;
    typedef std::shared_ptr<Texture> Texture_ptr;
    typedef std::shared_ptr<Material> Material_ptr;
    typedef std::shared_ptr<Tracer> Tracer_ptr;
    typedef std::shared_ptr<Object> Object_ptr;
    typedef std::shared_ptr<Background> Background_ptr;
    typedef std::shared_ptr<Light> Light_ptr;
    typedef std::vector<Object_ptr> Objects;
    typedef std::vector<Light_ptr> Lights;

    ~World();

    void build(const char *);
    void renderScene(const char *) const;
    void renderSceneWithMpi(int, char **, const char *);
    Color renderPixel(uint, uint) const;
    void displayPixel(uint, uint, const Color &, Texture_ptr &) const;
    void addObject(const Object_ptr &);
    void addLight(const Light_ptr &);
    void setAmbient(const Light_ptr &);
    void setBackground(const Background_ptr &);
    Intersection hitObjects(const Ray &) const;

    static World &getInstance();

    ViewPlane vp;
    Background_ptr background;
    Tracer_ptr tracer;
    Objects objects;
    Lights lights;
    Camera_ptr camera;
    Light_ptr ambient;

private:
    World();
};

#endif // WORLD_H
