CFLAGS = -std=c99 -Wall -Wextra -Isrc

all: project

src/color.o: src/color.c src/color.h
	cc -c $(CFLAGS) -o src/color.o src/color.c

src/tile.o: src/tile.c src/color.h src/tile.h
	cc -c $(CFLAGS) -o src/tile.o src/tile.c

src/web.o: src/web.c src/web.h src/board.h
	cc -c $(CFLAGS) -o src/web.o src/web.c

src/file.o: src/file.c src/file.h
	cc -c $(CFLAGS) -o src/file.o src/file.c

src/project.o: src/project.c src/tile.h src/color.h src/file.h src/web.h src/board.h
	cc -c $(CFLAGS) -o src/project.o src/project.c

src/board.o: src/board.c src/board.h src/tile.h
	cc -c $(CFLAGS) -o src/board.o src/board.c

project: src/project.o src/color.o src/tile.o src/file.o src/board.o src/web.o
	cc $(CFLAGS) -o project src/project.o src/color.o src/tile.o src/file.o src/board.o src/web.o 

test: src/color.o src/tile.o tst/test.c src/tile.h src/color.h src/file.h src/file.o src/board.o
	cc -c $(CFLAGS) -o tst/test.o tst/test.c
	cc $(CFLAGS) -o test src/tile.o src/color.o src/file.o src/board.o tst/test.o && ./test

clean:
	rm -f src/*.o tst/*.o project test output.html
