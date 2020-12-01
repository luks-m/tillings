#ifndef _PATTERN_H_
#define _PATTERN_H_

#include "board.h"

#define MAX_MOTIFS 7

//return the color of the tile if it is monochrome
struct color* is_monochrome(const struct tile* t);

//test if the tile (x,y) and the tiles edges of the tiles in the direction d1 and d2 are same coloured
int same_color(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, enum direction d1, enum direction d2);

//return the score if the tile (x,y) is part of a pattern
int pattern(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

#endif //_PATTERN_H_
