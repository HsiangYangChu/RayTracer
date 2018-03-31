#ifndef MULTI_JITTERED
#define MULTI_JITTERED

#include <sampler.h>

class MultiJittered: public Sampler
{
public:
    MultiJittered(uint num_samples = 1, uint num_sets = 83);
    ~MultiJittered() {}

    virtual void generateSamples();
};

#endif
