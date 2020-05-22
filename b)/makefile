CC=gcc
CFLAGS=-I.
DEPS = battleship.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: battleship.o quadtree.o bitmaps.o menus.o main.o
	$(CC) -o game battleship.o quadtree.o bitmaps.o menus.o main.o