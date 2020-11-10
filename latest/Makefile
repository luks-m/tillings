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

test: src/color.o src/tile.o tst/test.c src/tile.h src/color.h
	cc -c $(CFLAGS) -Isrc -o tst/test.o tst/test.c
	cc $(CFLAGS) -Isrc -o test tst/tile.o src/color.o tst/test.o && ./test

clean:
	rm -f src/*.o tst/*.o project test
