#ifndef VIEWPLANE_H
#define VIEWPLANE_H

#include <mymath.h>
#include <memory>
#include <serializable.h>

class Sampler;

struct ViewPlane: public Serializable
{
    uint hres;
    uint vres;
    uint num_samples;
    FLOAT s;
    FLOAT gamma;
    FLOAT inv_gamma;
    uint max_depth;
    std::unique_ptr<Sampler> sampler;

    ViewPlane();

    void setHres(FLOAT l_hres);
    void setVres(FLOAT l_vres);
    void setPixelSize(FLOAT l_s);
    void setGamma(FLOAT l_gamma);
    void setSampler(Sampler *l_sampler);
    void setNumSamples(uint);
    void setMaxDepth(uint);

    virtual void deserialize(TiXmlElement *);
};


#endif
