#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::draw()
{
	spaceShip.draw();
}

void Game::handleInput()
{
	if (IsKeyDown(KEY_A)) {
		spaceShip.moveLeft();
	}
	else if (IsKeyDown(KEY_D)) {
		spaceShip.moveRigth();
	}
}