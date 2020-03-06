#include "battleship.h"

Coordinate new_coord(int a, int b) {
	Coordinate c = (Coordinate) malloc(sizeof(Coordinate));
	c.x = a;
	c.y = b;
	return c;
}