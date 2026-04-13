#include <raylib.h>
#include "Grid.h"
#include "Blocks.cpp"

int main() {

	Color darkBlue = { 44, 44, 237, 255 };
	InitWindow(300, 600, "Raylib Tetris");
	SetTargetFPS(60);
	
	Grid grid = Grid();
	grid.Print();

	TBlock block = TBlock();
	
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	CloseWindow();
}