#include "random.h"

static uint32_t rng_state;

void RNG_Init(uint32_t seed)
{
	if (seed == 0)
	{
		seed = 0xa5a5a5a5;
	}
	rng_state = seed;
}

uint32_t RNG_Next(void)
{
	rng_state ^= rng_state << 13;
	rng_state ^= rng_state >> 17;
	rng_state ^= rng_state <<5;

	return rng_state;
}

uint8_t RNG_Range(uint8_t min, uint8_t max)
{
	return min + (RNG_Next() % (max - min +1));
}
