#pragma once
#include "Spaceship.h"
#include "Obstacle.h"

class Game {
public:
	Game();
	~Game();
	void draw();
	void update();
	void handleInput();
private:
	void deleteInactiveLasers();
	std::vector<Obstacle> CreateObstacles();
	Spaceship spaceShip;
	std::vector<Obstacle> obstacles;
};