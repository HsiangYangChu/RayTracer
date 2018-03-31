#ifndef SCENE_PARSER_H
#define SCENE_PARSER_H

#include <tinyxml/tinyxml.h>
#include <mymath.h>
#include <map>
#include <memory>

class Light;
class Background;
class World;
class Camera;
class Tracer;
class Material;
class Object;

class SceneParser
{
public:
    typedef std::shared_ptr<Material> Material_ptr;
    typedef std::shared_ptr<Object> Object_ptr;
    typedef std::shared_ptr<Light> Light_ptr;
    typedef std::shared_ptr<Camera> Camera_ptr;
    typedef std::shared_ptr<Tracer> Tracer_ptr;
    typedef std::shared_ptr<Background> Background_ptr;


    SceneParser(const char *);
    void build();

private:
    void init();

    void buildViewPlane();
    void buildAmbient();
    void buildBackground();
    void buildCamera();
    void buildObjects();
    void buildLights();
    void buildTracer();

    Light_ptr parseAmbient();
    Background_ptr parseBackground();
    Camera_ptr parseCamera();
    Tracer_ptr parseTracer();

    TiXmlDocument doc;
    World &w;

    TiXmlElement *scene;
    TiXmlElement *viewplane;
    TiXmlElement *ambient;
    TiXmlElement *background;
    TiXmlElement *tracer;
    TiXmlElement *objects;
    TiXmlElement *lights;
    TiXmlElement *camera;
};


#endif // SCENE_PARSER_H
