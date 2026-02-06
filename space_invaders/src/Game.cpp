#include "Game.h"
#include "iostream"

Game::Game()
{
}

Game::~Game()
{
}

void Game::update() {
	for (auto& laser: spaceShip.lasers) {
		laser.update();
	}

	deleteInactiveLasers();
	std::cout << "Vector size: " << spaceShip.lasers.size() << std::endl;
}

void Game::draw()
{
	spaceShip.draw();

	for (auto& laser : spaceShip.lasers) {
		laser.draw();
	}
}

void Game::handleInput()
{
	if (IsKeyDown(KEY_LEFT)) {
		spaceShip.moveLeft();
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		spaceShip.moveRigth();
	}
	else if(IsKeyDown(KEY_SPACE)) {
		spaceShip.fireLaser();
	}
}

void Game::deleteInactiveLasers()
{
	for (auto it = spaceShip.lasers.begin(); it != spaceShip.lasers.end();) {
		if (!it->active) {
			it = spaceShip.lasers.erase(it);
		}
		else {
			++ it;
		}
	}
}
