#include <raylib.h>
#include "Game.h"

int main() {
	Color grey = { 29,29,27, 255 };
	int windowWidth = 750;
	int windowHeigth = 700;

	InitWindow(windowWidth, windowHeigth, "C++ Space Invaders");

	SetTargetFPS(60);

	Game game;

	while (WindowShouldClose() == false)
	{
		game.handleInput();

		BeginDrawing();
		ClearBackground(grey);
		game.draw();

		EndDrawing();
	}

	CloseWindow();
}