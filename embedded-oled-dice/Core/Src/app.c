#include "stm32f4xx_hal.h"
#include "app.h"
#include "button.h"
#include "random.h"
#include "main.h"
#include "GFX.h"




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
	uint8_t dice = RNG_Range(1, 6);
	GFX_draw_fill_rect(0, 0, 128, 64,BLACK);

	switch (dice)
	{
	case 1:
		GFX_draw_fill_rect(0, 0, 64, 32, WHITE);
		break;
	case 2:
		GFX_draw_fill_rect(65, 0, 64, 32, WHITE);
		break;
	case 3:
		GFX_draw_fill_rect(0, 32, 64, 32, WHITE);
		break;
	case 4:
		GFX_draw_fill_rect(64, 33, 64, 32, WHITE);
		break;
	case 5:
		GFX_draw_fill_rect(0, 0, 64, 32, WHITE);
		GFX_draw_fill_rect(65, 0, 64, 32, WHITE);
		break;

	case 6:
		GFX_draw_fill_rect(0, 33, 64, 32, WHITE);
		GFX_draw_fill_rect(65, 33, 64, 32, WHITE);
		break;
	}
	SSD1306_display_repaint();
	}
}
