#ifndef _PATTERN_H_
#define _PATTERN_H_

#include "board.h"

#define NB_MOTIFS 7

//return the color of the tile if it is monochrome
struct color* is_monochrome(const struct tile* t);

//test if the tile (x,y) and the tiles edges of the tiles in the direction d1 and d2 are same coloured
int same_color(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, enum direction d1, enum direction d2);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in each direction
int pattern1(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in NORTH and SOUTH directions
int pattern2(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in WEST and EAST directions
int pattern3(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in NORTH and EAST directions
int pattern4(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in NORTH and WEST directions
int pattern5(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in SOUTH and WEST directions
int pattern6(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//test if there is a monochrome tile at position (x,y) with same color on others tiles in SOUTH and EAST directions
int pattern7(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//return the score if the tile (x,y) is part of a pattern, testing all the patterns from the most important to the less importants
int pattern(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

#endif //_PATTERN_H_
