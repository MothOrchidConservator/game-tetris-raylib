#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;

}

int main() {
	InitWindow(500, 620, "Raylib Tetris");
	SetTargetFPS(60);
	
	Font font = LoadFontEx("Assets/Font/monogram.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		UpdateMusicStream(game.music);
		game.HandleInput();
		if (EventTriggered(0.2)) {
			game.moveBlockDown();
		}
		BeginDrawing();
		ClearBackground(darkBlue);

		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		if (game.gameOver) {
			DrawTextEx(font, "Game Over", { 320, 450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3f, 6, lightBlue);
		
		char scoreText[10]; 
		sprintf_s(scoreText, sizeof(scoreText), "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
		
		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3f, 6, lightBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}
