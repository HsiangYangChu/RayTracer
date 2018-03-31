#include <samplers/regular.h>

Regular::Regular(uint num_samples, uint num_sets): Sampler(num_samples, num_sets)
{
    generateSamples();
}

void Regular::generateSamples()
{
	uint n = glm::sqrt(num_samples);

	for (uint j = 0; j < num_sets; j++)
	{
		for (uint p = 0; p < n; p++)
		{
			for (uint q = 0; q < n; q++)
			{
				samples.push_back(vec2((q + 0.5) / n, (p + 0.5) / n));
            }
        }
    }
}
