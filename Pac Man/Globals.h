#pragma once
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<vector>
#include<stdio.h>

enum THINGS {
	E, //nothing
	V, //vertical wall
	H, //horizontal wall
	TL, //top left corners
	TR, //top right corners
	BL, //bottom left corners
	BR, //bottom right corners
	P, //pellets
	PP, //power pellets
	CP, //
	CE, //
};
enum KEYS { up, down, left, right };
enum WALLS { TOP_LEFT, TOP_RIGHT, VERTICAL, HORIZONTAL, BOTTOM_LEFT, BOTTOM_RIGHT, };