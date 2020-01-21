#pragma once
#include"Globals.h"
class Wall {
private:
	int X;
	int Y;
	int ID;
public:
	Wall(int Xpos, int Ypos, int Type);
	void draw(int red, int green, int blue);
};