#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

void RNG_Init(uint32_t seed);
uint32_t TNG_Next(void);
uint8_t RNG_Range(uint8_t min, uint8_t max);

#endif
