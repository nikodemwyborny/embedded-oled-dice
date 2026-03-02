#include "button.h"
#include "main.h"

static volatile uint8_t button_event = 0;
static uint32_t last_press_time = 0;

void Button_Init(void)
{
	button_event = 0;
}

void Button_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == B1_Pin)
	{
		uint32_t now = HAL_GetTick();

		if( now - last_press_time > 200) //200ms debounce
		{
		button_event = 1;
		last_press_time = now;
		}
	}
}

uint8_t Button_GetEvent(void)
{
	if (button_event)
	{
		button_event = 0;
		return 1;
	}
	return 0;
}
