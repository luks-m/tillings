#include <stdio.h>
#include "color.h"
#include "tile.h"

struct tile {
  struct color* colored_tile[4];
};

// A tile that is empty
const struct tile* empty_tile()
{
	return NULL;
}

// A predicate telling if the tile is empty : return 1 if the tile is empty and 0 otherwise
int tile_is_empty(const struct tile* t)
{
  return (t == NULL);
}

// A comparator between tiles
int tile_equals(const struct tile* t1, const struct tile* t2)
{
	for (int i = 0 ; i < 4 ; ++i){
		if (t1->colored_tile[i] != t2 ->colored_tile[i])
			return 0;		
	}
	return 1;
}

// Accessors to the color of the edges
struct color* tile_edge(const struct tile* t, enum direction d)
{
	return t->colored_tile[d];
}

struct color* red_p = color_from_name("rouge");
struct color* blue_p = color_from_name("bleu");
struct color* green_p = color_from_name("vert");

struct tile tiles[MAX_DECK_SIZE] = {
									{red_p, red_p, red_p, red_p},
									{blue_p, blue_p, blue_p, blue_p},
									{green_p, green_p, green_p, green_p},
									{green_p, green_p, red_p, red_p},
									{blue_p, blue_p, red_p, red_p},
									{green_p, green_p, blue_p, blue_p},
									{red_p, green_p, green_p, red_p},
									{blue_p, red_p, red_p, blue_p},
									{green_p, blue_p, blue_p, green_p},
									{blue_p, green_p, red_p, green_p},
									{red_p, blue_p, green_p, blue_p},
									{green_p, red_p, blue_p, red_p},
									{green_p, blue_p, red_p, red_p},
									{red_p, green_p, blue_p, blue_p},
									{blue_p, red_p, green_p, green_p},
									{red_p, blue_p, blue_p, blue_p},
									{red_p, green_p, green_p, green_p},
									{green_p, red_p, red_p, red_p},
									{green_p, blue_p, blue_p, blue_p},
									{blue_p, red_p, red_p, red_p}
};

int tile_number[MAX_DECK_SIZE] = {
								  100, 100, 100, 100, 100,
								  100, 100, 100, 100, 100,
								  100, 100, 100, 100, 100,
								  100, 100, 100, 100, 100, 								  
};

// A function that fills a deck with tiles
// The contents of the deck `d` after the call must always be the same.
void deck_init(struct deck* d)
{
	for (int i = 0 ; i < MAX_DECK_SIZE ; ++i){
		d->cards[i].t = tiles[i];
		d->cards[i].n = tile_number[i];
		d->size += tile_number[i];
	}
}

