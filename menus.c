#include "battleship.h"

void print_menuB(bitmap a, bitmap b, bitmap c, bitmap d, bitmap e){

	printf("\n---------------");
 	printf("\n|  1. Square  |");
 	printf("\n---------------");
	printf("\n");
	print_bitmap(a);

	printf("\n----------------");
 	printf("\n| 2. Rectangle |");
 	printf("\n----------------");
	printf("\n");
	print_bitmap(b);

	printf("\n--------------");
 	printf("\n| 3. T Shape |");
 	printf("\n--------------");
	printf("\n");
	print_bitmap(c);

	printf("\n---------------");
 	printf("\n| 4. L Shape  |");
 	printf("\n---------------");
	printf("\n");
	print_bitmap(d);

	printf("\n---------------");
 	printf("\n| 5. U Shape  |");
 	printf("\n---------------");
	printf("\n");
	print_bitmap(e);
}