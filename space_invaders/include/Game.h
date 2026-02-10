#pragma once
#include "Spaceship.h"
#include "Obstacle.h"
#include "Alien.h"
#include "MysteryShip.h"

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
	std::vector<Alien> createAliens();
	void moveAliens();
	void moveDownAliens(int distance);
	void alienShootLaser();
	Spaceship spaceShip;
	std::vector<Obstacle> obstacles;
	std::vector<Alien> aliens;
	int aliensDirection;
	std::vector<Laser> alienLasers;
	constexpr static float alienLaseerShootInterval = 0.35;
	float timeLastAlienFireed;
	MysteryShip mysteryShip;
	float mysterShipSpawnInterval;
	float timeLastSpawn;
};