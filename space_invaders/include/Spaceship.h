#pragma once
#include <raylib.h>
#include "Laser.h"
#include <vector>

class Spaceship
{
public:
	Spaceship();
	~Spaceship();
	void draw();
	void moveLeft();
	void moveRigth();
	void fireLaser();
	std::vector<Laser> lasers;
private:
	Texture2D image;
	Vector2 position;
	double lastFireTime;
};