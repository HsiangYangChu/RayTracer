#include <sampler.h>
#include <algorithm>

Sampler::Sampler(uint nsmp, uint nsets):
  num_samples(nsmp), num_sets(nsets), count(0), jump(0)
{
    samples.reserve(num_samples * num_sets);
    setupShuffledIndices();
}

void Sampler::setupShuffledIndices()
{
    shuffled_indices.reserve(num_samples * num_sets);
    std::vector<uint> indices;

    for (uint i = 0; i < num_samples; i++)
    {
        indices.push_back(i);
    }

    for (uint i = 0; i < num_sets; i++)
    {
        std::random_shuffle(indices.begin(), indices.end());

        for (uint j = 0; j < num_samples; j++)
        {
            shuffled_indices.push_back(indices[j]);
        }
    }
}

vec2 Sampler::sampleUnitSquare()
{
    if (count % num_samples == 0)
    {
        jump = (rand_int() % num_sets) * num_samples;
    }

    return samples[jump + shuffled_indices[jump + count++ % num_samples]];
}

void Sampler::shuffleXCoordinates()
{
	for (uint p = 0; p < num_sets; p++)
	{
		for (uint i = 0; i <  num_samples - 1; i++)
		{
            uint target = rand_int() % num_samples + p * num_samples;
			FLOAT temp = samples[i + p * num_samples + 1].x;
			samples[i + p * num_samples + 1].x = samples[target].x;
			samples[target].x = temp;
		}
    }
}

void Sampler::shuffleYCoordinates()
{
	for (uint p = 0; p < num_sets; p++)
	{
		for (uint i = 0; i <  num_samples - 1; i++)
		{
            uint target = rand_int() % num_samples + p * num_samples;
			FLOAT temp = samples[i + p * num_samples + 1].y;
			samples[i + p * num_samples + 1].y = samples[target].y;
			samples[target].y = temp;
		}
    }
}

uint Sampler::getNumSamples() const
{
    return num_samples;
}

void Sampler::mapToUnitDisk()
{
    uint size = samples.size();

    disk_samples.clear();
    disk_samples.reserve(num_samples * num_sets);

    FLOAT q_pi = glm::quarter_pi<FLOAT>();

    vec2 sp;

    for (uint i = 0; i < size; i++)
    {
        sp.x = 2.0 * samples[i].x - 1;
        sp.y = 2.0 * samples[i].y - 1;

        FLOAT r, phi;

        if (sp.x > sp.y && sp.x > -sp.y)
        {
            r = sp.x;
            phi = (sp.x) ? sp.y / sp.x : 0;
        }
        else if (sp.x < sp.y && sp.x > -sp.y)
        {
            r = sp.y;
            phi = (sp.y) ? 2 - sp.x / sp.y : 0;
        }
        else if (sp.x < sp.y && sp.x < -sp.y)
        {
            r = -sp.x;
            phi = (sp.x) ? 4 + sp.y / sp.x : 0;
        }
        else
        {
            r = -sp.y;
            phi = (sp.y) ? 6 - sp.x / sp.y : 0;
        }

        phi *= q_pi;

        disk_samples[i].x = r * glm::cos(phi);
        disk_samples[i].y = r * glm::sin(phi);
    }
}

vec2 Sampler::sampleUnitDisk()
{
    if (count % num_samples == 0)
    {
        jump = (rand_int() % num_sets) * num_samples;
    }

    return disk_samples[jump + shuffled_indices[jump + count++ % num_samples]];
}

void Sampler::mapToHemisphere(FLOAT e)
{
    uint size = samples.size();

    hemisphere_samples.clear();
    hemisphere_samples.reserve(num_samples * num_sets);

    FLOAT PI = glm::pi<FLOAT>();

	for (uint j = 0; j < size; j++)
    {
		FLOAT cos_phi = glm::cos(2.0 * PI * samples[j].x);
		FLOAT sin_phi = glm::sin(2.0 * PI * samples[j].x);
		FLOAT cos_theta = glm::pow((1.0 - samples[j].y), 1.0 / (e + 1.0));
		FLOAT sin_theta = glm::sqrt (1.0 - cos_theta * cos_theta);
		FLOAT pu = sin_theta * cos_phi;
		FLOAT pv = sin_theta * sin_phi;
		FLOAT pw = cos_theta;
		hemisphere_samples.push_back(vec3(pu, pv, pw));
	}
}

vec3 Sampler::sampleHemisphere()
{
    if (count % num_samples == 0)
    {
        jump = (rand_int() % num_sets) * num_samples;
    }

    return hemisphere_samples[jump + shuffled_indices[jump + count++ % num_samples]];
}
