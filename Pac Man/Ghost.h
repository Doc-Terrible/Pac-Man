#pragma once
#include"Globals.h"
class Ghost{
private:
	int Xpos;
	int Ypos;
	char ID;
	int AliveTimer = 420;
	bool moving[4] = { false,false,false,false };
	bool moving2[4] = { false,false,false,false };
	bool alive = true;
public:
	Ghost(int X, int Y, char ghost);
	int GetX();
	int GetY();
	bool eaten();
	void collision(bool UP, bool DOWN, bool LEFT, bool RIGHT);
	void move();
	void turn(int x, int y, bool UP, bool DOWN, bool LEFT, bool RIGHT);
	void draw();
};

