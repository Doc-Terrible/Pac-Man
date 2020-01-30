#pragma once
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<vector>
#include<stdio.h>
#include<ctime>

enum THINGS {
	E, //nothing
	WL,
	WR,
	V, //vertical wall
	H, //horizontal wall
	TL, //top left corner
	TR, //top right corner
	BL, //bottom left corner
	BR, //bottom right corner
	B, //barrier that the ghosts can move though but pac man can't
	P, //pellet
	PP, //power pellet
	CP, //
	CE //
};
enum KEYS { up, down, left, right };
enum WALLS { TOP_LEFT, TOP_RIGHT, VERTICAL, HORIZONTAL, BOTTOM_LEFT, BOTTOM_RIGHT, BARRIER, FILLER };