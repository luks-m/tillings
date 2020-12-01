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
