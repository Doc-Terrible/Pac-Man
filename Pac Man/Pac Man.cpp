#include"Globals.h"
#include"Objects.h"
#include"Rainbow.h"

const int SCREEN_H = 720;
const int SCREEN_W = 720;
const int FPS = 60;

int MAP[36][36]{
	TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,
	V ,CP,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,CP,V ,
	V ,P ,TL,H ,H ,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,TR,P ,TL,H ,H ,H ,TR,P ,V ,
	V ,P ,V ,TL,H ,H ,H ,H ,H ,BR,P ,BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,BR,P ,BL,H ,H ,TR,V ,P ,V ,
	V ,P ,V ,V ,CP,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,CP,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,TL,H ,H ,H ,H ,H ,H ,H ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,H ,TR,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,BL,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,TR,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,P ,V ,V ,P ,V ,
	V ,P ,V ,V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,P ,BL,BR,P ,V ,
	V ,P ,V ,V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,CP,P ,P ,CP,V ,
	V ,P ,V ,V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,BR,BL,H ,H ,TR,P ,V ,
	V ,P ,BL,BR,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,H ,H ,H ,TR,V ,P ,V ,
	V ,CP,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,V ,V ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,P ,V ,
	BR,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,P ,BL,
	E ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,CP,E ,
	TR,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,V ,P ,TL,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,BL,BR,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,CP,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,H ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,CP,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,V ,
	V ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,P ,CP,V ,
	BL,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,H ,BR,
};

int main(){
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);

	bool quit = false;
	bool redraw = true;
	bool key[4] = { false,false,false,false };
	bool move[4] = { false,false,false,false };
	bool move2[4] = { false,false,false,false };
	int X = 30;
	int Y = 30;
	int Speed = 2;

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
		}
	}

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
					/*E*/if (key[up] && !(MAP[((Y - 10) / 20) - 1][(X - 10) / 20] >= V && MAP[((Y + 10) / 20) - 1][(X - 10) / 20] <= BR)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[up] = true;
						move2[up] = true;
					}
					else if (key[down] && !(MAP[((Y - 10) / 20) + 1][(X - 10) / 20] >= V && MAP[((Y - 10) / 20) + 1][(X - 10) / 20] <= BR)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[down] = true;
						move2[down] = true;
					}
					else if (key[left] && !(MAP[(Y - 10) / 20][((X - 10) / 20) - 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) - 1] <= BR)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[left] = true;
						move2[left] = true;
					}
					else if (key[right] && !(MAP[(Y - 10) / 20][((X - 10) / 20) + 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) + 1] <= BR)) {
						for (int i = 0; i < 4; i++) {
							move[i] = false;
							move2[i] = false;
						}
						move[right] = true;
						move2[right] = true;
					}
				}
			}

			/*E*/if (move[up] && move2[up])Y += -Speed;
			else if (move[down] && move2[down])Y += Speed;
			else if (move[left] && move2[left])X += -Speed;
			else if (move[right] && move2[right])X += Speed;
			
			redraw = true;
		}

		/* collision */
		if ((X - 10) % 20 == 0 && (Y - 10) % 20 == 0) {
			/*E*/if (!(MAP[(Y - 10) / 20 - 1][((X - 10) / 20)] >= V && MAP[(Y - 10) / 20 - 1][((X - 10) / 20)] <= BR))move2[up] = false;
			else if (!(MAP[(Y - 10) / 20 + 1][((X - 10) / 20)] >= V && MAP[(Y - 10) / 20 + 1][((X - 10) / 20)] <= BR))move2[down] = false;
			else if (!(MAP[(Y - 10) / 20][((X - 10) / 20) - 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) - 1] <= BR))move2[left] = false;
			else if (!(MAP[(Y - 10) / 20][((X - 10) / 20) + 1] >= V && MAP[(Y - 10) / 20][((X - 10) / 20) + 1] <= BR))move2[right] = false;
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
					al_draw_rectangle(i * 20 + 1, j * 20 + 1, i * 20 + 20, j * 20 + 20, al_map_rgb(50, 50, 50), 1);
					if (MAP[j][i] == P || MAP[j][i] == CP)al_draw_filled_circle(i * 20 + 10, j * 20 + 10, 3, al_map_rgb(255, 255, 255));
					if (MAP[j][i] == CP)al_draw_rectangle(i * 20 + 2, j * 20 + 2, i * 20 + 19, j * 20 + 19, al_map_rgb(255, 255, 0), 1);
				}
			}
			for (iter = walls.begin(); iter != walls.end(); iter++) {
				(*iter)->draw(R1.getColor('R'),R1.getColor('G'),R1.getColor('B'));
			}
			al_draw_filled_circle(X, Y, 10, al_map_rgb(255, 255, 0));
			al_draw_circle(X - 10, Y - 10, 2,al_map_rgb(0, 0, 255), 1);
			al_flip_display();
		}
			R1.Change();
	}
	al_destroy_display(display);
}