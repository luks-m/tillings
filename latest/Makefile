CFLAGS = -std=c99 -Wall

all: project

color.o: src/color.c
	cc -c $(CFLAGS) -o src/color.o src/color.c

tile.o: src/tile.c src/color.h
	cc -c $(CFLAGS) -o src/tile.o src/tile.c

projet.o: src/project.c src/tile.h src/color.h
	cc -c $(CFLAGS) -o src/project.o src/project.c

project: src/project.o src/color.o src/tile.o
	cc $(CFLAGS) -o project src/project.o src/color.o src/tile.o

test: 
	cc $(CFLAGS) tst/test.c -o test && ./test

clean:
	rm -f src/*.o tst/*.o project test
