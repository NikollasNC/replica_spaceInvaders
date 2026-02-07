#include "Game.h"

Game::Game()
{
	obstacles = CreateObstacles();
}

Game::~Game()
{
}

void Game::update() {
	for (auto& laser: spaceShip.lasers) {
		laser.update();
	}

	deleteInactiveLasers();
}

void Game::draw()
{
	spaceShip.draw();

	for (auto& laser : spaceShip.lasers) {
		laser.draw();
	}

	for (auto& obstacles : obstacles) {
		obstacles.draw();
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

std::vector<Obstacle> Game::CreateObstacles()
{
	int obstacleWidth = Obstacle::grid[0].size() * 3;
	float gap = (GetScreenWidth() - (4 * obstacleWidth)) / 5;

	for (int i = 0; i < 4; i++) {
		float offsetX = (i + 1) * gap + i * obstacleWidth;
		obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100) }));
	}
	return obstacles;
}
