#ifndef SPHERE_SKY_H
#define SPHERE_SKY_H

#include <background.h>
#include <memory>
#include <texture.h>
#include <cmath>

class SphereSky: public Background
{
public:
    typedef std::shared_ptr<Texture> Texture_ptr;

    SphereSky(const std::string &name): Background(name)
    {
    }

    ~SphereSky() {}

    virtual Color getL(const Ray &ray) const
    {
        vec3 dir = -ray.d;

        float pi = M_PI;

        float u = 0.5f + atan2(dir.z, dir.x) / (2.f * pi);
        float v = 0.5 - asin(dir.y) / pi;

        return texture->getPixelByUV(u, v);
    }

    virtual void deserialize(TiXmlElement *element)
    {
        TiXmlAttribute *attr = element->FirstAttribute();

        while (attr)
        {
            std::string name(attr->Name());

            if (name == "file")
            {
                texture = Texture::load(attr->Value());
            }

            attr = attr->Next();
        }

        assert(texture);
    }

    virtual Background *clone() const
    {
        return new SphereSky(*this);
    }

private:
    static SphereSky prototype;

    Texture_ptr texture;
};

#endif
