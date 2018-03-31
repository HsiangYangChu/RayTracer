#include <materials/phong.h>
#include <intersection.h>
#include <world.h>
#include <light.h>

Phong Phong::prototype("Phong");

Phong::Phong(const Phong &o):
  ambient_brdf(new Lambertian(*o.ambient_brdf)),
  diffuse_brdf(new Lambertian(*o.diffuse_brdf)),
  specular_brdf(new GlossySpecular(*o.specular_brdf))
{
}

Phong::Phong(const std::string &name): Material(name),
  ambient_brdf(new Lambertian(0.2)), diffuse_brdf(new Lambertian(0.7)),
  specular_brdf(new GlossySpecular)
{
}

Color Phong::shade(const Intersection &is) const
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
                L += specular_brdf->f(is, wi, wo) * ndotwi * lights[i]->getL(is);
            }

        }
    }

    return L;
}

Color Phong::areaLightShade(const Intersection & is) const
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
                L += specular_brdf->f(is, wi, wo) * ndotwi * lights[i]->getL(is) *
                     lights[i]->g(is) / lights[i]->pdf(is);
            }

        }
    }

    return L;
}

void Phong::deserialize(TiXmlElement *element)
{
    float ka = 0.2;
    float kd = 0.8;
    Color cd(1);
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

        attr = attr->Next();
    }

    ambient_brdf->setKd(ka);
    ambient_brdf->setCd(cd);
    diffuse_brdf->setKd(kd);
    diffuse_brdf->setCd(cd);
    specular_brdf->setKs(ks);
    specular_brdf->setE(e);
}
