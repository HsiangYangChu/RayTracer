#ifndef GLOSSY_REFLECTOR
#define GLOSSY_REFLECTOR

#include <materials/phong.h>

class GlossyReflector: public Phong
{
public:
    GlossyReflector(const std::string &);
    GlossyReflector(const GlossyReflector &);
    ~GlossyReflector() {}

    virtual Color areaLightShade(const Intersection &) const;
    virtual void deserialize(TiXmlElement *);
    virtual Material *clone() const;

private:
    static GlossyReflector prototype;

    GlossySpecular_ptr glossy_brdf;
};

#endif // GLOSSY_REFLECTOR
