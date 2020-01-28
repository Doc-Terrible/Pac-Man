#include"Globals.h"
#include"Objects.h"
#include"Rainbow.h"
#include"Ghost.h"

const int SCREEN_H = 720;
const int SCREEN_W = 720;
const int FPS = 60;

int MAP[36][36]{
	TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,
	V ,CP,P ,P ,P ,P ,PP,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,PP,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,CP,V ,
	V ,P ,TL,H ,H ,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,TR,P ,V ,
	V ,P ,V ,TL,H ,H ,H ,H ,H ,BR,P ,BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,BR,P ,BL,H ,H ,TR,V ,P ,V ,
	V ,P ,V ,V ,CP,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,CP,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,BL,H ,H ,H ,H ,TR,TL,H ,H ,H ,H ,H ,BR,P ,BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,CP,P ,P ,P ,P ,CP,V ,V ,CP,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,CP,P ,P ,P ,CP,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,TL,H ,H ,TR,P ,V ,V ,P ,TL,H ,H ,H ,TR,P ,TL,H ,H ,H ,TR,PP,TL,H ,TR,P ,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,V ,TL,H ,BR,P ,BL,BR,P ,BL,H ,H ,H ,BR,P ,BL,H ,H ,H ,BR,P ,BL,H ,BR,P ,V ,V ,P ,BL,BR,P ,V ,
	V ,P ,V ,V ,P ,V ,V ,CP,P ,CP,P ,P ,CP,P ,P ,P ,P ,P ,CP,P ,P ,CP,P ,P ,CP,P ,P ,P ,CP,V ,V ,CP,P ,P ,CP,V ,
	V ,P ,V ,V ,P ,V ,V ,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,TR,P ,TL,TR,P ,TL,H ,H ,H ,H ,H ,H ,BR,BL,H ,H ,TR,P ,V ,
	V ,P ,BL,BR,P ,BL,BR,P ,BL,H ,H ,H ,H ,H ,H ,H ,H ,BR,P ,V ,V ,P ,V ,V ,TL,H ,H ,H ,H ,H ,H ,H ,TR,V ,P ,V ,
	V ,CP,P ,P ,CP,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,V ,V ,P ,V ,V ,V ,CP,P ,P ,PP,P ,P ,CP,V ,V ,P ,V ,
	V ,P ,TL,H ,H ,H ,TR,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,BR,V ,P ,V ,V ,V ,P ,TL,H ,H ,H ,TR,P ,V ,V ,P ,V ,
	BR,P ,BL,H ,H ,H ,BR,P ,BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,BR,P ,BL,H ,BR,P ,BL,H ,H ,H ,BR,P ,BL,BR,P ,BL,
	WL,CP,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,CP,P ,P ,CP,CP,P ,P ,CP,P ,P ,P ,CP,P ,P ,P ,P ,P ,CP,P ,P ,CP,WR,
	TR,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,P ,TL,H ,B ,B ,H ,TR,P ,TL,H ,H ,H ,H ,H ,H ,H ,TR,P ,TL,TR,P ,TL,
	V ,P ,BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,V ,P ,V ,CE,CE,CE,CE,V ,P ,V ,TL,H ,H ,H ,H ,H ,H ,BR,P ,BL,BR,P ,V ,
	V ,CP,P ,P ,P ,P ,CP,P ,P ,P ,P ,CP,V ,V ,P ,V ,CE,CE,CE,CE,V ,P ,V ,V ,CP,P ,P ,P ,P ,P ,P ,CP,P ,P ,CP,V ,
	V ,P ,TL,H ,H ,TR,PP,TL,H ,H ,TR,P ,BL,BR,P ,BL,H ,H ,H ,H ,BR,P ,V ,V ,P ,TL,H ,H ,H ,H ,TR,P ,TL,TR,P ,V ,
	V ,P ,BL,H ,H ,BR,P ,BL,H ,TR,V ,CP,P ,P ,CP,P ,P ,P ,P ,P ,P ,CP,V ,V ,P ,BL,H ,H ,H ,TR,V ,P ,V ,V ,P ,V ,
	V ,CP,P ,P ,P ,P ,CP,P ,CP,V ,V ,P ,TL,TR,P ,TL,H ,H ,H ,H ,H ,H ,BR,V ,CP,P ,PP,P ,CP,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,TL,H ,H ,H ,H ,TR,P ,V ,V ,P ,V ,V ,P ,BL,H ,H ,H ,H ,H ,H ,H ,BR,P ,TL,H ,TR,P ,V ,V ,P ,BL,BR,P ,V ,
	V ,P ,V ,TL,H ,H ,H ,BR,P ,BL,BR,P ,V ,V ,CP,P ,P ,P ,P ,CP,P ,P ,P ,P ,CP,V ,V ,V ,P ,V ,V ,CP,PP,P ,CP,V ,
	V ,P ,V ,V ,CP,P ,P ,P ,CP,P ,P ,CP,V ,BL,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,H ,BR,V ,V ,P ,V ,V ,P ,TL,TR,P ,V ,
	V ,P ,V ,V ,P ,TL,H ,TR,P ,TL,TR,P ,BL,H ,H ,H ,H ,H ,BR,P ,BL,H ,H ,H ,H ,H ,H ,BR,P ,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,V ,H ,V ,P ,V ,V ,CP,P ,P ,P ,P ,P ,CP,P ,CP,P ,P ,P ,P ,CP,P ,P ,P ,CP,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,BL,BR,P ,BL,H ,BR,P ,V ,V ,P ,TL,H ,H ,H ,TR,P ,TL,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,BR,V ,P ,V ,V ,P ,V ,
	V ,CP,P ,P ,CP,P ,P ,P ,CP,V ,V ,P ,V ,TL,H ,H ,BR,P ,BL,H ,H ,H ,H ,BR,P ,V ,TL,H ,H ,H ,BR,P ,BL,BR,P ,V ,
	V ,P ,TL,TR,P ,TL,H ,TR,P ,BL,BR,P ,V ,V ,CP,P ,P ,CP,P ,P ,P ,P ,P ,P ,CP,V ,V ,CP,P ,P ,P ,CP,P ,P ,CP,V ,
	V ,P ,V ,V ,P ,V ,V ,V ,CP,PP,P ,CP,V ,V ,P ,TL,H ,H ,H ,H ,H ,H ,H ,TR,P ,V ,V ,P ,TL,H ,TR,P ,TL,TR,P ,V ,
	V ,P ,V ,V ,P ,V ,V ,V ,P ,TL,TR,P ,V ,V ,P ,V ,V ,V ,V ,V ,V ,V ,V ,V ,P ,V ,V ,P ,V ,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,BL,BR,P ,BL,H ,BR,P ,BL,BR,P ,BL,BR,P ,BL,H ,H ,H ,H ,H ,H ,H ,BR,P ,BL,BR,P ,BL,H ,BR,P ,BL,BR,P ,V ,
	V ,CP,P ,P ,CP,P ,P ,P ,CP,P ,P ,CP,P ,P ,CP,P ,P ,P ,P ,PP,P ,P ,P ,P ,CP,P ,P ,CP,P ,P ,P ,CP,P ,P ,CP,V ,
	BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,BR,
};

int main(){
	srand(time(NULL));
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);

	bool quit = false; //if game ended
	bool redraw = true;
	bool QColor = true; //does rainbow class change fast
	bool power = false;
	bool key[4] = { false,false,false,false }; //if keys are being pressed
	bool move[4] = { false,false,false,false }; //if trying to move in direction
	bool move2[4] = { false,false,false,false }; //if moving in direction
	int X = 0; //player X position
	int Y = 0; //player Y position
	int Speed = 2; //player speed
	int PowerTimer = 420; //timer for power pellets
	int score = 0;

	int randcorner = rand() % 86;
	bool run = true;
	for (int i = 1; i < 35; i++) {
		for (int j = 1; j < 35; j++) {
			if (MAP[j][i] == CP) {
				if (randcorner <= 0 && run) {
					X = (i * 20) + 10;
					Y = (j * 20) + 10;
					run = false;
				}
				else randcorner--;
			}
		}
	}

	Rainbow R1(0, 0, 0, .1);

	std::vector<Wall*> walls;
	std::vector<Wall*>::iterator iter;
	for (int i = 0; i < 36; i++) {
		for (int j = 0; j < 36; j++) {
			/*E*/if (MAP[j][i] == TL) {
				Wall* NewWall = new Wall(i, j, TOP_LEFT);
				walls.push_back(NewWall);
			}
			else if (MAP[j][i] == BL) {
				Wall* NewWall = new Wall(i, j, BOTTOM_LEFT);
				walls.push_back(NewWall);
			}
			else if (MAP[j][i] == TR) {
				Wall* NewWall = new Wall(i, j, TOP_RIGHT);
				walls.push_back(NewWall);
			}
			else if (MAP[j][i] == BR) {
				Wall* NewWall = new Wall(i, j, BOTTOM_RIGHT);
				walls.push_back(NewWall);
			}
			else if (MAP[j][i] == H) {
				Wall* NewWall = new Wall(i, j, HORIZONTAL);
				walls.push_back(NewWall);
			}
			else if (MAP[j][i] == V) {
				Wall* NewWall = new Wall(i, j, VERTICAL);
				walls.push_back(NewWall);
			}
			else if (MAP[j][i] == B) {
				Wall* NewWall = new Wall(i, j, BARRIER);
				walls.push_back(NewWall);
			}
		}
	}
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 36; j++) {
			if ((MAP[j][i] >= V && MAP[j][i] <= BR) && (MAP[j + 1][i] >= V && MAP[j + 1][i] <= BR) && (MAP[j][i + 1] >= V && MAP[j][i + 1] <= BR) && (MAP[j + 1][i + 1] >= V && MAP[j + 1][i + 1] <= BR)) {
				Wall* NewWall = new Wall(i, j, FILLER);
				walls.push_back(NewWall);
			}
		}
	}

	std::vector<Ghost*> Ghosts;
	std::vector<Ghost*>::iterator iter2;
	Ghost* NewGhost = new Ghost((1 * 20) + 10, (1 * 20) + 10, 'B');
	Ghosts.push_back(NewGhost);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!quit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;

		/* movement */
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if ((X - 10) % 20 == 0 && (Y - 10) % 20 == 0) {
				if (MAP[(Y - 10) / 20][(X - 10) / 20] == CP || MAP[(Y - 10) / 20][(X - 10) / 20] == CE) {
					/*E*/if (key[up] && !(MAP[((Y - 10) / 20) - 1][(X - 10) / 20] >= V && MAP[((Y - 10) / 20) - 1][(X - 10) / 20] <= B)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[up] = true;
						move2[up] = true;
					}
					else if (key[down] && !(MAP[((Y - 10) / 20) + 1][(X - 10) / 20] >= V && MAP[((Y - 10) / 20) + 1][(X - 10) / 20] <= B)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[down] = true;
						move2[down] = true;
					}
					else if (key[left] && !(MAP[(Y - 10) / 20][((X - 10) / 20) - 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) - 1] <= B)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[left] = true;
						move2[left] = true;
					}
					else if (key[right] && !(MAP[(Y - 10) / 20][((X - 10) / 20) + 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) + 1] <= B)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[right] = true;
						move2[right] = true;
					}
				}
			}

			/* moving player */
			/*E*/if (move[up] && move2[up])Y += -Speed;
			else if (move[down] && move2[down])Y += Speed;
			else if (move[left] && move2[left])X += -Speed;
			else if (move[right] && move2[right])X += Speed;

			/* ghosts */
			for (iter2 = Ghosts.begin(); iter2 != Ghosts.end(); iter2++) {
				if (((*iter2)->GetX() - 10) % 20 == 0 && ((*iter2)->GetY() - 10) % 20 == 0) {
					if (MAP[((*iter2)->GetY() - 10) / 20][((*iter2)->GetX() - 10) / 20] == CP || MAP[((*iter2)->GetY() - 10) / 20][((*iter2)->GetX() - 10) / 20] == CE) {
						bool turn[4];
						/*E*/if (!(MAP[(((*iter2)->GetY() - 10) / 20) - 1][((*iter2)->GetX() - 10) / 20] >= V && MAP[(((*iter2)->GetY() - 10) / 20) - 1][((*iter2)->GetX() - 10) / 20] <= BR))turn[up] = true;
						else if (!(MAP[(((*iter2)->GetY() - 10) / 20) + 1][((*iter2)->GetX() - 10) / 20] >= V && MAP[(((*iter2)->GetY() - 10) / 20) + 1][((*iter2)->GetX() - 10) / 20] <= B))turn[down] = true;
						else if (!(MAP[((*iter2)->GetY() - 10) / 20][(((*iter2)->GetX() - 10) / 20) - 1] >= V && MAP[((*iter2)->GetY() - 10) / 20][(((*iter2)->GetX() - 10) / 20) - 1] <= B))turn[left] = true;
						else if (!(MAP[((*iter2)->GetY() - 10) / 20][(((*iter2)->GetX() - 10) / 20) + 1] >= V && MAP[((*iter2)->GetY() - 10) / 20][(((*iter2)->GetX() - 10) / 20) + 1] <= B))turn[right] = true;
						(*iter2)->turn(X, Y, turn[up], turn[down], turn[left], turn[right]);
					}
				}
				(*iter2)->move();
			}
			
			redraw = true;
		}

		/* collision */
		if ((X - 10) % 20 == 0 && (Y - 10) % 20 == 0) {
			/*E*/if (move2[up] && (MAP[((Y - 10) / 20) - 1][(X - 10) / 20] >= V && MAP[((Y - 10) / 20) - 1][(X - 10) / 20] <= B))move2[up] = false;
			else if (move2[down] && (MAP[((Y - 10) / 20) + 1][(X - 10) / 20] >= V && MAP[((Y - 10) / 20) + 1][(X - 10) / 20] <= B))move2[down] = false;
			else if (move2[left] && (MAP[(Y - 10) / 20][((X - 10) / 20) - 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) - 1] <= B))move2[left] = false;
			else if (move2[right] && (MAP[(Y - 10) / 20][((X - 10) / 20) + 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) + 1] <= B))move2[right] = false;

			/*E*/if (MAP[(Y - 10) / 20][(X - 10) / 20] == P) {
				MAP[(Y - 10) / 20][(X - 10) / 20] = E;
				score++;
			}
			else if (MAP[(Y - 10) / 20][(X - 10) / 20] == CP) {
				MAP[(Y - 10) / 20][(X - 10) / 20] = CE;
				score++;
			}
			else if (MAP[(Y - 10) / 20][(X - 10) / 20] == PP) {
				MAP[(Y - 10) / 20][(X - 10) / 20] = E;
				power = true;
				PowerTimer = 420;
				score += 5;
			}
		}

		/* when key is pressed */
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
			case ALLEGRO_KEY_W:
				if (!move[down]) {
					key[left] = false;
					key[right] = false;
					key[up] = true;
				}
				break;
			case ALLEGRO_KEY_DOWN:
			case ALLEGRO_KEY_S:
				if (!move[up]) {
					key[left] = false;
					key[right] = false;
					key[down] = true;
				}
				break;
			case ALLEGRO_KEY_LEFT:
			case ALLEGRO_KEY_A:
				if (!move[right]) {
					key[up] = false;
					key[down] = false;
					key[left] = true;
				}
				break;
			case ALLEGRO_KEY_RIGHT:
			case ALLEGRO_KEY_D:
				if (!move[left]) {
					key[up] = false;
					key[down] = false;
					key[right] = true;
				}
				break;
			case ALLEGRO_KEY_ESCAPE:
				quit = true;
				break;
			}
		}

		/* draw */
		if (redraw && al_event_queue_is_empty(event_queue)) {
			al_clear_to_color(al_map_rgb(0,0,0));
			for (int i = 0; i < 36; i++) {
				for (int j = 0; j < 36; j++) {
					if (MAP[j][i] == P || MAP[j][i] == CP)al_draw_filled_circle(i * 20 + 10, j * 20 + 10, 3, al_map_rgb(255, 255, 255));
					if (MAP[j][i] == PP)al_draw_filled_circle(i * 20 + 10, j * 20 + 10, 6, al_map_rgb(0, 127, 0));
					if (MAP[j][i] == CP || MAP[j][i] == CE)al_draw_rectangle(i * 20 + 2, j * 20 + 2, i * 20 + 19, j * 20 + 19, al_map_rgb(255, 255, 0), 1);
				}
			}
			for (iter = walls.begin(); iter != walls.end(); iter++) {
				(*iter)->draw(R1.getColor('R'),R1.getColor('G'),R1.getColor('B'));
			}
			for (iter2 = Ghosts.begin(); iter2 != Ghosts.end(); iter2++) {
				(*iter2)->draw();
			}
			al_draw_filled_circle(X, Y, 10, al_map_rgb(255, 255, 0));
			al_flip_display();
			R1.Change();
			if (QColor) {
				for (int i = 0; i < 4; i++) {
					R1.Change();
				}
			}
			if (power) {
				for (int i = 0; i < 124; i++) {
					R1.Change();
				}
				PowerTimer--;
				if (PowerTimer <= 0)power = false;
			}
			if (R1.getColor('B') == 255)QColor = false;
		}
	}
	al_destroy_display(display);
}