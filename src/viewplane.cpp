#include <viewplane.h>
#include <sampler.h>
#include <samplers/multi_jittered.h>
#include <samplers/regular.h>

ViewPlane::ViewPlane(): hres(1), vres(1), s(1.0), gamma(1.0), inv_gamma(1.0),
  max_depth(3)
{
}

void ViewPlane::setSampler(Sampler *l_sampler)
{
    sampler.reset(l_sampler);
    num_samples = sampler->getNumSamples();
}

void ViewPlane::setHres(FLOAT l_hres)
{
    hres = l_hres;
}

void ViewPlane::setVres(FLOAT l_vres)
{
    vres = l_vres;
}

void ViewPlane::setPixelSize(FLOAT l_s)
{
    s = l_s;
}

void ViewPlane::setGamma(FLOAT l_gamma)
{
    gamma = l_gamma;
    inv_gamma = 1.0 / gamma;
}

void ViewPlane::setNumSamples(uint ns)
{
    num_samples = ns;

    if (ns == 1)
    {
        sampler.reset(new Regular(1));
    }
    else
    {
        sampler.reset(new MultiJittered(ns));
    }
}

void ViewPlane::setMaxDepth(uint depth)
{
    max_depth = depth;
}

void ViewPlane::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "hres")
        {
            parseUint(attr, hres);
        }
        else if (name == "vres")
        {
            parseUint(attr, vres);
        }
        else if (name == "pixel_size")
        {
            parseDouble(attr, s);
        }
        else if (name == "samples")
        {
            uint ns;

            parseUint(attr, ns);
            setNumSamples(ns);
        }
        else if (name == "depth")
        {

            parseUint(attr, max_depth);
        }

        attr = attr->Next();
    }
}
