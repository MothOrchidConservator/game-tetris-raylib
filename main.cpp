#include <raylib.h>
#include "Grid.h"

int main() {

	Color darkBlue = { 44, 44, 237, 255 };
	InitWindow(300, 600, "Raylib Tetris");
	SetTargetFPS(60);
	
	Grid grid = Grid();
	grid.Print();
	
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);
		grid.Draw();

		EndDrawing();
	}

	CloseWindow();
}