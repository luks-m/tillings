#include <stdlib.h>
#include "board.h"
#include "color.h"
#include "pattern.h"
#include "tile.h"

int score_tab[] = {34, 20, 10};

struct color* is_monochrome(const struct tile* t)
{
  if (tile_edge(t, NORTH) == tile_edge(t, SOUTH) && tile_edge(t, WEST) == tile_edge(t, EAST) && tile_edge(t, NORTH) == tile_edge(t, EAST))
    return tile_edge(t, NORTH);
  else
    return NULL;
}

int same_color(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, enum direction d1, enum direction d2)
{
  int new_x = 0;
  int new_y = 0;
  struct color* c = is_monochrome(tile(b,x,y));
  if (c == NULL)
    return 0;
  else {
    new_x = x + x_difference(d1);
    new_y = y + y_difference(d1);
    if (new_x < 0 || new_x > MAX_SIZE_BOARD || new_y < 0 || new_y > MAX_SIZE_BOARD || tile(b, new_x, new_y) == NULL)
      return 0;
    else {
      if (tile_edge(tile(b, new_x, new_y), give_opposite(d1)) != c)
	return 0;
    }
      new_x = x + x_difference(d2);
      new_y = y + y_difference(d2);
    if (new_x < 0 || new_x > MAX_SIZE_BOARD || new_y < 0 || new_y > MAX_SIZE_BOARD || tile(b, new_x, new_y) == NULL)
      return 0;
    else {
      if (tile_edge(tile(b, new_x, new_y), give_opposite(d2)) != c)
	return 0;
    }
  }
  return 1;
}

int pattern(struct board_cell b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y)
{
  if (same_color(b, x, y, NORTH, SOUTH) && same_color(b, x, y, WEST, EAST))
    return score_tab[0];
  if (same_color(b, x, y, NORTH, SOUTH) || same_color(b, x, y, WEST, EAST))
    return score_tab[1];
  if (same_color(b, x, y, NORTH, EAST) || same_color(b, x, y, NORTH, WEST) || same_color(b, x, y, SOUTH, WEST) || same_color(b, x, y, SOUTH, EAST))
    return score_tab[2];
  return 0;
}

