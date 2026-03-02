#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

void Button_Init(void);
void Button_EXTI_Callback(uint16_t GPIO_Pin);
uint8_t Button_GetEvent(void);

#endif
