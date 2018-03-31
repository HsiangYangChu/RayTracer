#include <materials/reflective.h>
#include <intersection.h>
#include <world.h>
#include <light.h>
#include <tracer.h>

Reflective Reflective::prototype("Reflective");

Reflective::Reflective(const std::string &name): Phong(name),
  reflective_brdf(new PerfectSpecular(0.4))
{
}

Reflective::Reflective(const Reflective &o): Phong(o),
  reflective_brdf(new PerfectSpecular(*o.reflective_brdf))
{
}

Color Reflective::shade(const Intersection &is) const
{
    Color L(Phong::shade(is));

    vec3 wo = -is.ray.d;
    vec3 wi;

    Color fr = reflective_brdf->sample_f(is, wi, wo);

    Ray ray(is.hit_point, wi);
    float ndotwi = glm::dot(is.normal, wi);

    L += fr * is.w.tracer->traceRay(ray, is.depth + 1) * ndotwi;

    return L;
}

Color Reflective::areaLightShade(const Intersection &is) const
{
    Color L(Phong::areaLightShade(is));

    vec3 wo = -is.ray.d;
    vec3 wi;

    Color fr = reflective_brdf->sample_f(is, wi, wo);

    Ray ray(is.hit_point, wi);
    float ndotwi = glm::dot(is.normal, wi);

    L += fr * is.w.tracer->traceRay(ray, is.depth + 1) * ndotwi;

    return L;
}

void Reflective::deserialize(TiXmlElement *element)
{
    float ka = 0.2;
    float kd = 0.8;
    Color cd(1);
    float ks = 0.1;
    float e = 10;
    float kr = 0.4;
    Color cr(1);

    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "ka")
        {
            parseFloat(attr, ka);
        }
        else if (name == "kd")
        {
            parseFloat(attr, kd);
        }
        else if (name == "cd")
        {
            parseColor(attr, cd);
        }
        else if (name == "ks")
        {
            parseFloat(attr, ks);
        }
        else if (name == "e")
        {
            parseFloat(attr, e);
        }
        else if (name == "kr")
        {
            parseFloat(attr, kr);
        }
        else if (name == "cr")
        {
            parseColor(attr, cr);
        }

        attr = attr->Next();
    }

    ambient_brdf->setKd(ka);
    ambient_brdf->setCd(cd);
    diffuse_brdf->setKd(kd);
    diffuse_brdf->setCd(cd);
    specular_brdf->setKs(ks);
    specular_brdf->setE(e);
    reflective_brdf->setKr(kr);
    reflective_brdf->setCr(cr);
}
