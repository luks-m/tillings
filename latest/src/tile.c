#include <stdio.h>
#include "color.h"
#include "tile.h"

struct tile {
  struct color* colored_tile[4];
};

#define MAX_DECK_SIZE 100

struct deck_pair {
  const struct tile* t;
  unsigned int n;
};

struct deck {
  struct deck_pair cards[MAX_DECK_SIZE];
  unsigned int size;
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



// A function that fills a deck with tiles
// The contents of the deck `d` after the call must always be the same.
void deck_init(struct deck* d)
{
	struct tile t1 ={{&red, &red, &red, &red}};
	struct tile t2 ={{&blue, &blue, &blue, &blue}};
	struct tile t3 ={{}};
	struct tile t4 ={};
	struct tile t5 ={};
	struct tile t6 ={};
	struct tile t7 ={};
	struct tile t8 ={};
	struct tile t9 ={};
	struct tile t10 ={};
	struct tile t11 ={};
	struct tile t12 ={};
	struct tile t13 ={};
	struct tile t14 ={};
	struct tile t15 ={};
	struct tile t16 ={};
	struct tile t17 ={};
	struct tile t18 ={};
	struct tile t19 ={};
	struct tile t20 ={};
}

