#include <stdio.h>
#include "board.h"

int opposite_direction[MAX_DIRECTION] = {SOUTH, NORTH, WEST, EAST};
int direction_x[MAX_DIRECTION] = {0,0,1,-1};
int direction_y[MAX_DIRECTION] = {-1,1,0,0};

int owner(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y)
{
	if (x < 0 || y < 0 || y > MAX_SIZE_BOARD || x > MAX_SIZE_BOARD)
		return -1;
	return b[x][y].p;
}

const struct tile* tile(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y)
{
	if (x < 0 || y < 0 || y > MAX_SIZE_BOARD || x > MAX_SIZE_BOARD)
		return empty_tile();
	return b[x][y].t;
}

void change_owner(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, int new_owner)
{
	if (x >= 0 && y >= 0 && y < MAX_SIZE_BOARD && x < MAX_SIZE_BOARD)
		b[x][y].p = new_owner;
}

void change_tile(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, const struct tile* new_tile)
{
	if (x >= 0 && y >= 0 && y < MAX_SIZE_BOARD && x < MAX_SIZE_BOARD)
		b[x][y].t = new_tile;
}

int give_opposite(enum direction d)
{
	return opposite_direction[d];
}

int x_difference(enum direction d)
{
	return direction_x[d];
}

int y_difference(enum direction d)
{
	return direction_y[d];
}

int test_position(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, const struct tile* t)
{
  int tested_direction[MAX_DIRECTION] = {1,1,1,1}; //tabular of bool
  
  //coordinates of the tile compared with tile t
  int new_x = 0;
  int new_y = 0;
  int nb_not_empty_tile = 0; //number of not empty tiles near to the position (x,y)
  
  if (tile(b, x, y) != NULL)  //a player cannot replace an already placed tile
    return 0;

  //reducing the number of tests because of the board's limitations
  if (x == 0)
    tested_direction[WEST] = 0;
  if (x == MAX_SIZE_BOARD - 1)
    tested_direction[EAST] = 0;
  if (y == 0)
    tested_direction[NORTH] = 0;
  if (y == MAX_SIZE_BOARD - 1)
    tested_direction[SOUTH] = 0;

  //testing the correspondance between edges
  for (int i = 0; i < MAX_DIRECTION; i++) {
    if (tested_direction[i] == 1) {
      new_x = x + x_difference(i);
      new_y = y + y_difference(i);
      if (!tile_is_empty(tile(b, new_x, new_y))) { //no comparison needed with empty tile
	nb_not_empty_tile++;
	if (tile_edge(t, i) != tile_edge(tile(b, new_x, new_y), give_opposite(i)))
	  return 0;
      }
    }
  }
  return (nb_not_empty_tile > 0); //testing the connectedness
}

int tile_placement(const struct tile *t, struct board_cell board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int size, int player)
{
  for (int y = 0; y < size; y++)
    for (int x = 0; x < size; x++)
      if (test_position(board, x, y, t) == 1) {
	change_tile(board, x, y, t);
	change_owner(board, x, y, player);
	return 1;
      }
  return 0;
}

void draw_board(struct board_cell board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int size)
{
  struct color* c1;
  struct color* c2;
  struct color* c3;
  struct color* c4;
  for (int y = 0 ; y < size ; y++){
    printf("\n\n");
    for (int x = 0 ; x < size ; x++){
      if (tile_is_empty(tile(board, x, y)))
	printf("E,E,E,E,N \t");
      else{
	c1 = tile_edge(tile(board,x,y),NORTH);
	c2 = tile_edge(tile(board,x,y),SOUTH);
	c3 = tile_edge(tile(board,x,y),EAST);
	c4 = tile_edge(tile(board,x,y),WEST);
	printf("%s,%s,%s,%s,%d \t",
	       color_cstring(c1),color_cstring(c2) ,color_cstring(c3) ,color_cstring(c4), owner(board,x,y));
      }
    }
  }
  printf("\n");
}
