#include "Player.h"

void drawPaddle(float xPos, float yPos, unsigned color)
{
	sfw::drawLine(xPos, yPos - 50, xPos, yPos + 50, color);
	sfw::drawLine(xPos - 30, yPos - 50, xPos - 30, yPos + 50, GREEN);
	sfw::drawLine(xPos, yPos - 50, xPos - 30, yPos - 50, GREEN);
	sfw::drawLine(xPos, yPos + 50, xPos - 30, yPos + 50, GREEN);
}