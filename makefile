CC=gcc
CFLAGS=-I.
DEPS = battleship.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

matrix: main_matrix.c
	$(CC) -o game battleship.c bitmaps.c menus.c main_matrix.c

quad: main_quad.c
	$(CC) -o game quadtree.c bitmaps.c menus.c main_quad.c