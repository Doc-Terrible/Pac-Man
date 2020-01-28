#pragma once
#include"Globals.h"
class Ghost{
private:
	int Xpos;
	int Ypos;
	char ID;
	int AliveTimer = 420;
	bool moving[4] = { false,false,false,false };
	bool alive = true;
public:
	Ghost(int X, int Y, char ghost);
	int GetX();
	int GetY();
	bool eaten();
	void move();
	void turn(int x, int y, bool up, bool down, bool left, bool right);
	void draw();
};

