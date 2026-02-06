#pragma once
#include "Spaceship.h"

class Game {
public:
	Game();
	~Game();
	void draw();
	void update();
	void handleInput();
private:
	Spaceship spaceShip;
};