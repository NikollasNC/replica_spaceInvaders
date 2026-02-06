#include "Spaceship.h"

Spaceship::Spaceship()
{
	image = LoadTexture("space_invaders/assets/sprites/spaceship.png");
	position.x = (GetScreenWidth() - image.width)/2;
	position.y = GetScreenHeight() - image.height;
	lastFireTime = 0.0;
}

Spaceship::~Spaceship()
{
	UnloadTexture(image);
}

void Spaceship::draw()
{
	DrawTextureV(image, position, WHITE);
}

void Spaceship::moveLeft()
{
	position.x -= 7;
	if (position.x < 0) {
		position.x = 0;
	}
}

void Spaceship::moveRigth()
{
	position.x += 7;
	if (position.x > GetScreenWidth() - image.width) {
		position.x = GetScreenWidth() - image.width;
	}
}

void Spaceship::fireLaser()
{
	if (GetTime() - lastFireTime >= 0.35) {
		lasers.push_back(Laser({position.x + image.width/2,position.y}, - 6));
		lastFireTime = GetTime();
	}
}