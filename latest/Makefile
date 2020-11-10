CFLAGS = -std=c99 -Wall -Wextra

all: project

src/color.o: src/color.c
	cc -c $(CFLAGS) -o src/color.o src/color.c

src/tile.o: src/tile.c src/color.h
	cc -c $(CFLAGS) -o src/tile.o src/tile.c

src/project.o: src/project.c src/tile.h src/color.h
	cc -c $(CFLAGS) -o src/project.o src/project.c

project: src/project.o src/color.o src/tile.o
	cc $(CFLAGS) -o project src/project.o src/color.o src/tile.o

test: src/color.o src/tile.o tst/test.c
	cp src/color.{o,c,h} tst/
	cp src/tile.{o,c,h} tst/
	cc -c $(FLAGS) -o tst/test.o tst/test.c
	cc $(CFLAGS) -o test tst/tile.o tst/color.o test.o && ./test

clean:
	rm -f src/*.o tst/*.{o,h} tst/color.c tst/tile.c project test
