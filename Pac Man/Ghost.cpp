#include "Ghost.h"

Ghost::Ghost(int X, int Y, char ghost){
	Xpos = X;
	Ypos = Y;
	ID = ghost;
}

int Ghost::GetX(){
	return Xpos;
}

int Ghost::GetY(){
	return Ypos;
}

bool Ghost::eaten(){
	return false;
}

void Ghost::collision(bool UP, bool DOWN, bool LEFT, bool RIGHT){
	/*E*/if (moving[up] && UP)moving[up] = false;
	else if (moving[down] && DOWN)moving[down] = false;
	else if (moving[left] && LEFT)moving[left] = false;
	else if (moving[right] && RIGHT)moving[right] = false;
}

void Ghost::move(){
	/*E*/if (moving[up])Ypos += -2;
	else if (moving[down])Ypos += 2;
	else if (moving[left])Xpos += -2;
	else if (moving[right])Xpos += 2;
}

void Ghost::turn(int x, int y, bool UP, bool DOWN, bool LEFT, bool RIGHT){
	srand(time(NULL));
	/* Up */
	/*E*/if (y < Ypos) {
		/* Right */
		/*E*/if (x > Xpos) {
			/*E*/if (!UP && !RIGHT && !(moving2[down] || moving2[left])) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				bool UorR = rand() % 1;
				if (UorR) {
					moving[up] = true;
					moving2[up] = true;
				}
				else {
					moving[right] = true;
					moving2[right] = true;
				}
				printf(" flag 1");
			}
			else if (!UP && !moving2[down]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[up] = true;
				moving2[up] = true;
				printf(" flag 2");
			}
			else if (!RIGHT && !moving2[left]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[right] = true;
				moving2[right] = true;
				printf(" flag 3");
			}
		}
		/* Left */
		else if (x < Xpos) {
			/*E*/if (!UP && !LEFT && !(moving2[down] || moving2[right])) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				bool UorL = rand() % 1;
				if (UorL) {
					moving[up] = true;
					moving2[up] = true;
				}
				else {
					moving[left] = true;
					moving2[left] = true;
				}
				printf(" flag 4");
			}
			else if (!UP && !moving2[down]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[up] = true;
				moving2[up] = true;
				printf(" flag 5");
			}
			else if (!LEFT && !moving2[right]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[left] = true;
				moving2[left] = true;
				printf(" flag 6");
			}
		}
	}
	/* Down */
	else if (y > Ypos) {
		/* Right */
		/*E*/if (x > Xpos) {
			/*E*/if (!DOWN && !RIGHT && !(moving2[up] || moving2[left])) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				bool DorR = rand() % 1;
				if (DorR) {
					moving[down] = true;
					moving2[down] = true;
				}
				else {
					moving[right] = true;
					moving2[right] = true;
				}
				printf(" flag 7");
			}
			else if (!DOWN && !moving2[up]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[down] = true;
				moving2[down] = true;
				printf(" flag 8");
			}
			else if (!RIGHT && !moving2[left]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[right] = true;
				moving2[right] = true;
				printf(" flag 9");
			}
		}
		/* Left */
		else if (x < Xpos) {
			/*E*/if (!DOWN && !LEFT && !(moving2[up] || moving2[right])) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				bool DorL = rand() % 1;
				if (DorL) {
					moving[down] = true;
					moving2[down] = true;
				}
				else {
					moving[left] = true;
					moving2[left] = true;
				}
				printf(" flag 10");
			}
			else if (!DOWN && !moving2[up]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[down] = true;
				moving2[down] = true;
				printf(" flag 11");
			}
			else if (!LEFT && !moving2[right]) {
				for (int i = 0; i < 4; i++) {
					moving[i] = false;
				}
				moving[left] = true;
				moving2[left] = true;
				printf(" flag 12");
			}
		}
	}
	/* if player Y and Ghost Y is same */
	else if (!(y > Ypos || y < Ypos)) {
		/*E*/if (x < Xpos && !LEFT && !moving2[right]) {
			for (int i = 0; i < 4; i++) {
				moving[i] = false;
			}
			moving[left] = true;
			moving2[left] = true;
			printf(" flag 13");
		}
		else if (x > Xpos && !RIGHT && !moving2[left]) {
			for (int i = 0; i < 4; i++) {
				moving[i] = false;
			}
			moving[right] = true;
			moving2[right] = true;
			printf(" flag 14");
		}
	}
	/* if player X and Ghost X is same */
	else if (!(x > Xpos || x < Xpos)) {
		/*E*/if (y < Ypos && !UP && !moving2[down]) {
			for (int i = 0; i < 4; i++) {
				moving[i] = false;
			}
			moving[up] = true;
			moving2[up] = true;
			printf(" flag 15");
		}
		else if (y > Ypos && !DOWN && !moving2[up]) {
			for (int i = 0; i < 4; i++) {
				moving[i] = false;
			}
			moving[down] = true;
			moving2[down] = true;
			printf(" flag 16");
		}
	}
	if (!moving[up] && !moving[down] && !moving[left] && !moving[right]) {
		bool run = true;
		int UDLorR = rand() % 4;
		while (run) {
			/*E*/if (!UP && UDLorR == up && !moving2[down])UDLorR = rand() % 4;
			else if (!DOWN && UDLorR == down && !moving2[up])UDLorR = rand() % 4;
			else if (!RIGHT && UDLorR == left && !moving2[right])UDLorR = rand() % 4;
			else if (!LEFT && UDLorR == right && !moving2[left])UDLorR = rand() % 4;
			else run = false;
		}
		for (int i = 0; i < 4; i++) {
			moving[i] = false;
		}
		/*E*/if (UDLorR == up)moving[up] = true;
		else if (UDLorR == down)moving[down] = true;
		else if (UDLorR == left)moving[left] = true;
		else if (UDLorR == right)moving[right] = true;
		printf(" flag 17");
	}
	for (int i = 0; i < 4; i++) {
		moving2[i] = moving[i];
	}
}

void Ghost::draw(){
	al_draw_filled_circle(Xpos, Ypos, 9, al_map_rgb(255, 0, 0));
}
