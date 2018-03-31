#include <materials/glossy_reflector.h>
#include <intersection.h>
#include <world.h>
#include <tracer.h>

GlossyReflector GlossyReflector::prototype("GlossyReflector");

GlossyReflector::GlossyReflector(const std::string &name): Phong(name),
  glossy_brdf(new GlossySpecular)
{
}

GlossyReflector::GlossyReflector(const GlossyReflector &o): Phong(o),
  glossy_brdf(new GlossySpecular(*o.glossy_brdf))
{
}

Material *GlossyReflector::clone() const
{
    return new GlossyReflector(*this);
}

Color GlossyReflector::areaLightShade(const Intersection &is) const
{
    Color L(Phong::areaLightShade(is));
    vec3 wo(-is.ray.d);

    float pdf;
    vec3 wi;

    Color rc = glossy_brdf->sample_f(is, wi, wo, pdf);

    Ray refl_ray(is.hit_point, wi);
    float ndotwi = glm::dot(is.normal, wi);

    return L + rc * is.w.tracer->traceRay(refl_ray, is.depth + 1) * ndotwi / pdf;
}

void GlossyReflector::deserialize(TiXmlElement *element)
{
    float ka = 0.2;
    float kd = 0.8;
    float kr = 0.1;
    Color cd(1);
    Color cr(1);
    float ks = 0.1;
    float e = 10;

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
    glossy_brdf->setKs(kr);
    glossy_brdf->setCr(cr);
    glossy_brdf->setE(e);

    glossy_brdf->setSampler();
}
