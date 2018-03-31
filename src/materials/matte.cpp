#include <materials/matte.h>
#include <brdfs/lambertian.h>
#include <intersection.h>
#include <world.h>
#include <light.h>

Matte Matte::prototype("Matte");

Matte::Matte(const Matte &o):
  ambient_brdf(new Lambertian(*o.ambient_brdf)),
  diffuse_brdf(new Lambertian(*o.diffuse_brdf))
{
}

Matte::Matte(const std::string &name): Material(name),
  ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian)
{
}

Matte::Matte():
  ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian)
{
}

void Matte::setKa(float ka)
{
    ambient_brdf->setKd(ka);
}

void Matte::setKd(float kd)
{
    diffuse_brdf->setKd(kd);
}

void Matte::setCd(const Color &color)
{
    diffuse_brdf->setCd(color);
}

Color Matte::shade(const Intersection &is) const
{
    vec3 wo = -is.ray.d;
    Color L = ambient_brdf->rho(is, wo) * is.w.ambient->getL(is);

    const World::Lights &lights = is.w.lights;

    for (uint i = 0; i < lights.size(); i++)
    {
        vec3 wi = lights[i]->getDirection(is);
        float ndotwi = glm::dot(wi, is.normal);

        if (ndotwi > 0)
        {

            Ray ray(is.hit_point, wi);

            if (!lights[i]->inShadow(ray, is))
            {
                L += diffuse_brdf->f(is, wi, wo) * ndotwi * lights[i]->getL(is);
            }

        }
    }

    return L;
}

Color Matte::areaLightShade(const Intersection &is) const
{
    vec3 wo = -is.ray.d;
    Color L = ambient_brdf->rho(is, wo) * is.w.ambient->getL(is);

    const World::Lights &lights = is.w.lights;

    for (uint i = 0; i < lights.size(); i++)
    {
        vec3 wi = lights[i]->getDirection(is);
        float ndotwi = glm::dot(wi, is.normal);

        if (ndotwi > 0)
        {

            Ray ray(is.hit_point, wi);

            if (!lights[i]->inShadow(ray, is))
            {
                L += diffuse_brdf->f(is, wi, wo) * ndotwi * lights[i]->getL(is) *
                     lights[i]->g(is) / lights[i]->pdf(is);
            }

        }
    }

    return L;
}

void Matte::deserialize(TiXmlElement *element)
{
    float ka = 0.2;
    float kd = 0.8;
    Color cd(1);

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

        attr = attr->Next();
    }

    ambient_brdf->setKd(ka);
    ambient_brdf->setCd(cd);
    diffuse_brdf->setKd(kd);
    diffuse_brdf->setCd(cd);
}
