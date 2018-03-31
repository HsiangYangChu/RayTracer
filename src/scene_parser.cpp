#include <scene_parser.h>
#include <world.h>
#include <objects/objects.h>
#include <lights/lights.h>
#include <backgrounds/backgrounds.h>
#include <materials/materials.h>
#include <cameras/cameras.h>
#include <tracers/tracers.h>
#include <datastore.h>

SceneParser::SceneParser(const char *filename):
  doc(filename), w(World::getInstance())
{
}

void SceneParser::build()
{
    init();

    buildViewPlane();
    buildTracer();
    buildAmbient();
    buildBackground();
    buildCamera();
    buildObjects();
    buildLights();

    DataStore::getInstance().clear();
}

void SceneParser::init()
{
    doc.LoadFile();

    scene = doc.FirstChildElement("scene");
    assert(scene);

    DataStore::getInstance().init(scene);

    viewplane = scene->FirstChildElement("viewplane");
    ambient = scene->FirstChildElement("ambient");
    background = scene->FirstChildElement("background");
    tracer = scene->FirstChildElement("tracer");
    objects = scene->FirstChildElement("objects");
    lights = scene->FirstChildElement("lights");
    camera = scene->FirstChildElement("camera");
}

void SceneParser::buildViewPlane()
{
    if (viewplane)
    {
        w.vp.deserialize(viewplane);
    }
}

SceneParser::Light_ptr SceneParser::parseAmbient()
{
    if (ambient)
    {
        TiXmlElement *ambient_class = ambient->FirstChildElement();

        if (ambient_class)
        {
            Light_ptr light = Light::create(ambient_class);

            if (light)
            {
                return light;
            }
        }
    }

    return Light_ptr(new Ambient);
}

void SceneParser::buildAmbient()
{
    Light_ptr ambient_light = parseAmbient();

    w.setAmbient(ambient_light);
}

SceneParser::Background_ptr SceneParser::parseBackground()
{
    if (background)
    {
        TiXmlElement *background_class = background->FirstChildElement();

        if (background_class)
        {
            Background_ptr bg = Background::create(background_class);

            if (bg)
            {
                return bg;
            }
        }
    }

    return Background_ptr(new SingleColor);
}

void SceneParser::buildBackground()
{
    w.setBackground(parseBackground());
}

SceneParser::Camera_ptr SceneParser::parseCamera()
{
    if (camera)
    {
        TiXmlElement *camera_class = camera->FirstChildElement();

        if (camera_class)
        {
            Camera_ptr camera = Camera::create(camera_class);

            if (camera)
            {
                return camera;
            }
        }
    }

    return Camera_ptr(new Pinhole);
}

SceneParser::Tracer_ptr SceneParser::parseTracer()
{
    if (tracer)
    {
        TiXmlElement *tracer_class = tracer->FirstChildElement();

        Tracer_ptr tracer = Tracer::create(tracer_class);

        if (tracer)
        {
            return tracer;
        }
    }

    return Tracer_ptr(new RayCast);
}

void SceneParser::buildCamera()
{
    w.camera = parseCamera();
}

void SceneParser::buildObjects()
{
    if (objects)
    {
        TiXmlElement *object_class = objects->FirstChildElement();

        while (object_class)
        {
            Object_ptr object = Object::create(object_class);
            assert(object);

            w.addObject(object);

            object_class = object_class->NextSiblingElement();
        }
    }
}

void SceneParser::buildLights()
{
    if (lights)
    {
        TiXmlElement *light_class = lights->FirstChildElement();

        while (light_class)
        {
            Light_ptr light = Light::create(light_class);
            assert(light);

            w.addLight(light);

            light_class = light_class->NextSiblingElement();
        }
    }
}

void SceneParser::buildTracer()
{
    w.tracer = parseTracer();
}
