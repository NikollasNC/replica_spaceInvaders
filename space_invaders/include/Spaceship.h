#pragma once
#include <raylib.h>

class Spaceship
{
public:
	Spaceship();
	~Spaceship();
	void draw();
	void moveLeft();
	void moveRigth();
	void fireLaser();
private:
	Texture2D image;
	Vector2 position;
};