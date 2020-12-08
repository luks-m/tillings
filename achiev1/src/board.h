#ifndef _BOARD_H_
#define _BOARD_H_

#include "tile.h"

#define MAX_SIZE_BOARD 50
#define NO_OWNER -1

struct board_cell {
  const struct tile* t; //a tile
  int p; //the owner of the tile
};

//Return the owner of the tile at position (x,y)
int owner(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//Return the tile at position (x,y)
const struct tile* tile(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y);

//Change the owner of the tile at position (x,y)
void change_owner(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, int new_owner);

//Change the tile at position (x,y)
void change_tile(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, const struct tile* t);

//Give the opposite direction
int give_opposite(enum direction d); 

//Give the x translation to go to the tile in direction d 
int x_difference(enum direction d); 

//Give the y translation to go to the tile in direction d
int y_difference(enum direction d);

//return 1 if the position is available and 0 if it is not
int test_position(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, const struct tile* t);

//test if the tile can be placed on the board and place it if it is possible
int tile_placement(const struct tile *t, struct board_cell board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int size, int player);

//show a representation of the board in the terminal
void draw_board(struct board_cell board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int size);

#endif //_BOARD_H_
