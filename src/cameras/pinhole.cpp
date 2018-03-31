#include <cameras/pinhole.h>
#include <world.h>
#include <sampler.h>
#include <tracer.h>

Pinhole Pinhole::prototype("Pinhole");

Pinhole::Pinhole(const std::string &name): Camera(name)
{
}

Pinhole::Pinhole()
{
}

Camera *Pinhole::clone() const
{
    return new Pinhole(*this);
}

Color Pinhole::renderPixel(uint w, uint h) const
{
    const ViewPlane &vp = world.vp;
    Color pixel_color(0);
    Ray ray(eye);

    FLOAT inv_num_samples = 1.0 / vp.num_samples;

    for (uint j = 0; j < vp.num_samples; j++)
    {
        vec2 pp = vp.sampler->sampleUnitSquare();

        FLOAT x = vp.s * (w - 0.5 * vp.hres + pp.x);
        FLOAT y = vp.s * (h - 0.5 * vp.vres + pp.y);
        vec3 dir(x, y, -d);
        ray.d = rayDirection(glm::normalize(dir));

        pixel_color += world.tracer->traceRay(ray);
    }

    return pixel_color * float(inv_num_samples);
}

void Pinhole::setFOV(FLOAT angle)
{
    angle = glm::radians(angle);
    const ViewPlane &vp = world.vp;
    d = vp.vres * vp.s / (2.0 * glm::tan(angle / 2));
}

void Pinhole::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "eye")
        {
            parseVec3(attr, eye);
        }
        else if (name == "look_at")
        {
            parseVec3(attr, look_at);
        }
        else if (name == "distance")
        {
            parseDouble(attr, d);
        }
        else if (name == "fov")
        {
            FLOAT angle;

            parseDouble(attr, angle);
            setFOV(angle);
        }

        attr = attr->Next();
    }
}
