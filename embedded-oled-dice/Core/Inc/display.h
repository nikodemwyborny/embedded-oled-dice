#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
} Dice_t;

void Display_DrawDice(uint8_t value);
void DrawDiceBase(void);

#endif
