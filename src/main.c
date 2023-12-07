#include "render.h"

int main(void)
{
	if (!createWindow())
	{
		return 1;
	}

	uint32_t color = 0x00FF0000;
	while (!windowShouldClose())
	{
		// update
		processEvents();
		
		// draw
		clearBuffer(color);
		swapBuffer();
	}
	
	destroyWindow();
	return 0;
}
