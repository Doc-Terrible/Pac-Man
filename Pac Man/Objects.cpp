#include "Objects.h"

Wall::Wall(int Xpos, int Ypos, int Type){
	X = Xpos;
	Y = Ypos;
	ID = Type;
}

void Wall::draw(int red, int green, int blue){
	if (ID == TOP_LEFT) {
		al_draw_arc(X * 20 + 20, Y * 20 + 20, 10, 3.14159, 1.57079, al_map_rgb(red, green, blue), 11);
		al_draw_arc(X * 20 + 20, Y * 20 + 20, 16, 3.14159, 1.57079, al_map_rgb(0, 0, 255), 2);
		al_draw_arc(X * 20 + 20, Y * 20 + 20, 4, 3.14159, 1.57079, al_map_rgb(0, 0, 255), 2);
	}
	else if (ID == BOTTOM_LEFT) {
		al_draw_arc(X * 20 + 20, Y * 20, 10, 3.14159, -1.57079, al_map_rgb(red, green, blue), 11);
		al_draw_arc(X * 20 + 20, Y * 20, 16, 3.14159, -1.57079, al_map_rgb(0, 0, 255), 2);
		al_draw_arc(X * 20 + 20, Y * 20, 4, 3.14159, -1.57079, al_map_rgb(0, 0, 255), 2);
	}
	else if (ID == TOP_RIGHT) {
		al_draw_arc(X * 20, Y * 20 + 20, 10, 0, -1.57079, al_map_rgb(red, green, blue), 11);
		al_draw_arc(X * 20, Y * 20 + 20, 16, 0, -1.57079, al_map_rgb(0, 0, 255), 2);
		al_draw_arc(X * 20, Y * 20 + 20, 4, 0, -1.57079, al_map_rgb(0, 0, 255), 2);
	}
	else if (ID == BOTTOM_RIGHT) {
		al_draw_arc(X * 20, Y * 20, 10, 0, 1.57079, al_map_rgb(red, green, blue), 11);
		al_draw_arc(X * 20, Y * 20, 16, 0, 1.57079, al_map_rgb(0, 0, 255), 2);
		al_draw_arc(X * 20, Y * 20, 4, 0, 1.57079, al_map_rgb(0, 0, 255), 2);
	}
	else if (ID == HORIZONTAL) {
		al_draw_line(X * 20, Y * 20 + 10, X * 20 + 20, Y * 20 + 10, al_map_rgb(red, green, blue), 10);
		al_draw_line(X * 20, Y * 20 + 4, X * 20 + 20, Y * 20 + 4, al_map_rgb(0, 0, 255), 2);
		al_draw_line(X * 20, Y * 20 + 16, X * 20 + 20, Y * 20 + 16, al_map_rgb(0, 0, 255), 2);
	}
	else if (ID == VERTICAL) {
		al_draw_line(X * 20 + 10, Y * 20, X * 20 + 10, Y * 20 + 20, al_map_rgb(red, green, blue),10);
		al_draw_line(X * 20 + 4, Y * 20, X * 20 + 4, Y * 20 + 20, al_map_rgb(0, 0, 255), 2);
		al_draw_line(X * 20 + 16, Y * 20, X * 20 + 16, Y * 20 + 20, al_map_rgb(0, 0, 255), 2);
	}
	else if (ID == BARRIER) {
		al_draw_line(X * 20, Y * 20 + 5, X * 20 + 20, Y * 20 + 5, al_map_rgb(0, 0, 255), 2);
		al_draw_line(X * 20, Y * 20 + 15, X * 20 + 20, Y * 20 + 15, al_map_rgb(0, 0, 255), 2);
		al_draw_line(X * 20, Y * 20 + 10, X * 20 + 20, Y * 20 + 10, al_map_rgb(red, green, blue), 8);
	}
	else if (ID == FILLER) {
		al_draw_filled_rectangle(X * 20 + 10, Y * 20 + 10, X * 20 + 30, Y * 20 + 30, al_map_rgb(red,green,blue));
	}
}