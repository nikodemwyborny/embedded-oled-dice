#include "display.h"
#include "GFX.h"
#include "SSD1306.h"


Dice_t dice = {
		.w =48,
		.h = 48
};

void DrawDiceBase(void)
{
		dice.x = (SSD1306_WIDTH - dice.w) /2;
		dice.y = (SSD1306_HEIGHT - dice.h) /2;


	GFX_draw_fill_rect(dice.x, dice.y, dice.w, dice.h, BLACK);
}

void Draw_Dot(int x, int y)
{
	GFX_draw_fill_rect(x-3, y-3, 6, 6, WHITE);
}

void Display_DrawDice(uint8_t value)
{
	GFX_draw_fill_rect(0,0,SSD1306_WIDTH ,SSD1306_HEIGHT ,WHITE);

	DrawDiceBase();
	switch (value)
	{
	case 1:
		Draw_Dot(dice.x + dice.w/2, dice.y + dice.h/2);
		break;
	case 2:
		Draw_Dot(dice.x + dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + dice.h/4);
		break;
	case 3:
		Draw_Dot(dice.x + dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + dice.w/2, dice.y + dice.h/2);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + dice.h/4);
		break;
	case 4:
		Draw_Dot(dice.x + dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + dice.h/4);
		Draw_Dot(dice.x + dice.w/4, dice.y + dice.h/4);
		break;
	case 5:
		Draw_Dot(dice.x + dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + dice.h/4);
		Draw_Dot(dice.x + dice.w/4, dice.y + dice.h/4);
		Draw_Dot(dice.x + dice.w/2, dice.y + dice.h/2);
		break;
	case 6:
		Draw_Dot(dice.x + dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + 3*dice.h/4);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + dice.h/2);
		Draw_Dot(dice.x + dice.w/4, dice.y + dice.h/2);
		Draw_Dot(dice.x + 3*dice.w/4, dice.y + dice.h/4);
		Draw_Dot(dice.x + dice.w/4, dice.y + dice.h/4);
		break;
	default:
		break;

	}
	SSD1306_display_repaint();
}
