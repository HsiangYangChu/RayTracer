#ifndef PINHOLE_H
#define PINHOLE_H

#include <camera.h>
#include <ray.h>

struct Pinhole: public Camera
{
    Pinhole(const std::string &);
    Pinhole();
    ~Pinhole() {}

    void setFOV(FLOAT );
    virtual Color renderPixel(uint, uint) const;
    virtual void deserialize(TiXmlElement *);
    virtual Camera *clone() const;

private:
    static Pinhole prototype;
};

#endif
