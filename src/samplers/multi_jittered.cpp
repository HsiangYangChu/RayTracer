#include <samplers/multi_jittered.h>

MultiJittered::MultiJittered(uint num_samples, uint num_sets):
  Sampler(num_samples, num_sets)
{
    generateSamples();
}

void MultiJittered::generateSamples()
{
	// num_samples needs to be a perfect square

	uint n = sqrt(num_samples);
	FLOAT subcell_width = 1.0 / (num_samples);

	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the
	// initial patterns

	vec2 fill_point;
	for (uint j = 0; j < num_samples * num_sets; j++)
		samples.push_back(fill_point);

	// distribute points in the initial patterns

	for (uint p = 0; p < num_sets; p++)
		for (uint i = 0; i < n; i++)
			for (uint j = 0; j < n; j++) {
				samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0, subcell_width);
				samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0, subcell_width);
			}

	// shuffle x coordinates

	for (uint p = 0; p < num_sets; p++)
		for (uint i = 0; i < n; i++)
			for (uint j = 0; j < n; j++) {
				uint k = rand_int(j, n - 1);
				FLOAT t = samples[i * n + j + p * num_samples].x;
				samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
				samples[i * n + k + p * num_samples].x = t;
			}

	// shuffle y coordinates

	for (uint p = 0; p < num_sets; p++)
		for (uint i = 0; i < n; i++)
			for (uint j = 0; j < n; j++) {
				uint k = rand_int(j, n - 1);
				FLOAT t = samples[j * n + i + p * num_samples].y;
				samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
				samples[k * n + i + p * num_samples].y = t;
		}
}
