#ifndef REGULAR_H
#define REGULAR_H

#include <sampler.h>

class Regular: public Sampler
{
public:
    Regular(uint num_samples = 1, uint num_sets = 83);
    ~Regular() {}

    virtual void generateSamples();
};

#endif
