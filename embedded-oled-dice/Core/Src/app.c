#include "stm32f4xx_hal.h"
#include "app.h"
#include "button.h"
#include "random.h"
#include "display.h"



void App_Init(void)
{
	Button_Init();
	RNG_Init(HAL_GetTick());
}

void App_Logic(void)
{
	static uint8_t seeded = 0;

	if (Button_GetEvent())
	{
		if (!seeded)
		{
			RNG_Init(HAL_GetTick());
			seeded = 1;
		}
	uint8_t diceValue = RNG_Range(1, 6);
	Display_DrawDice(diceValue);
	}
}
