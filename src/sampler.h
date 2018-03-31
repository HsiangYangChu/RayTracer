#ifndef SAMPLER_H
#define SAMPLER_H

#include <mymath.h>
#include <vector>

class Sampler
{
public:
    Sampler(uint nsmp = 1, uint nsets = 83);
    virtual ~Sampler() {}

    virtual void generateSamples() = 0;
    void setupShuffledIndices();
    vec2 sampleUnitSquare();
    void shuffleXCoordinates();
    void shuffleYCoordinates();
    uint getNumSamples() const;
    void mapToUnitDisk();
    void mapToHemisphere(FLOAT);
    vec2 sampleUnitDisk();
    vec3 sampleHemisphere();

protected:
    uint num_samples;
    uint num_sets;
    std::vector<vec2> samples;
    std::vector<vec2> disk_samples;
    std::vector<vec3> hemisphere_samples;
    std::vector<uint> shuffled_indices;
    unsigned long count;
    uint jump;
};

#endif
