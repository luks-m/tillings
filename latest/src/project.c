#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "tile.h"
#include "color.h"
#include "file.h"

#define MAX_PLAYERS 20
#define MAX_SIZE_BOARD 50

//Global number of players
static int nb_players = 2;

//Global size of the board
static int board_size = 10;

// Global seed for the random number generator
static int seed = 0;


////////////////////////////////////////////////////////////////
// Function for parsing the options of the program
// Currently available options are :
// -s <seed> : sets the seed
// -b <board> : sets the size of the board
// -n <number of players> : sets the number of players

void parse_opts(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "b:s:n:")) != -1) {
    switch (opt) {
    case 'n':
      if (atoi(optarg) > MAX_PLAYERS) {
	fprintf(stderr, "Usage: %s [-n number of players <= %d]\n",
		argv[0], MAX_PLAYERS);
	exit(EXIT_FAILURE);		
      }
      nb_players = atoi(optarg);
      break;
    case 'b':
      if (atoi(optarg) > MAX_SIZE_BOARD) {
	fprintf(stderr, "Usage: %s [-b size of the board <= %d]\n",
		argv[0], MAX_SIZE_BOARD);
	exit(EXIT_FAILURE);		
      }
      board_size = atoi(optarg);
      break;
    case 's':
      seed = atoi(optarg);
      srand(seed);
      break;
    default: //"?"//
      fprintf(stderr, "Usage: %s [-n number of players] [-b size of the board] [-s seed] \n",
              argv[0]);
      exit(EXIT_FAILURE);
    }
  }
}

////////////////////////////////////////////////////////////////

//transform a deck of deck_pair into a file with all the tiles
void transform(struct deck d, struct file* f)
{
  for (unsigned int i = 0 ; i < d.size ; i++)
    for  (unsigned int j = 0 ; j < d.cards[i].n ; j++)
      push(f, d.cards[i].t);
}

void first_tile(const struct tile* b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], struct file f_hand[])
{
  int first_player = 0;
  b[rand()%board_size][rand()%board_size] = pop(&f_hand[first_player]);
}

//return 1 if the position is available and 0 if it is not
int test_position(const struct tile* b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, const struct tile* t)
{
  int tested_direction[MAX_DIRECTION] = {1,1,1,1}; //tabular of bool
  int opposite_direction[MAX_DIRECTION] = {SOUTH, NORTH, WEST, EAST};
  int direction_x[MAX_DIRECTION] = {0,0,1,-1};
  int direction_y[MAX_DIRECTION] = {-1,1,0,0};
  
  //coordinates of the tile compared with tile t
  int new_x = 0;
  int new_y = 0;
  int nb_not_empty_tile = 0; //number of not empty tiles near to the position (x,y)
  
  if (b[x][y] != NULL)  //a player cannot replace an already placed tile
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
      new_x = x + direction_x[i];
      new_y = y + direction_y[i];
      if (!tile_is_empty(b[new_x][new_y])) {  //no comparison needed with empty tile,
	nb_not_empty_tile++;
	if (tile_edge(t, i) != tile_edge(b[new_x][new_y], opposite_direction[i]))
	  return 0;
      }
    }
  }
  return (nb_not_empty_tile > 0); //testing the connectedness
}

int tile_placement(const struct tile *t, const struct tile* board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int size)
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (test_position(board, i, j, t) == 1) {
	board[i][j] = t;
	return 1;
      }
  return 0;
}

int main(int argc,  char* argv[])
{
  struct file deck_players[MAX_PLAYERS] = {}; //a tabular that represent the decks of the players
  const struct tile* board[MAX_SIZE_BOARD][MAX_SIZE_BOARD] = {};
  for (int i = 0; i < MAX_SIZE_BOARD; i++)
    for (int j = 0; j < MAX_SIZE_BOARD; j++)
      board[i][j] = empty_tile();
  
  parse_opts(argc, argv);
  printf("Number of players : %d\n", nb_players);
  printf("Size of the board : %d\n", board_size);
  printf("Seed : %d\n", seed);
  
  //Initialization of the game
  struct deck base_deck = {};
  struct file deck_file = {};
  int skip = 0;
  int active_player = 0;
  
  deck_init(&base_deck);   //initialization of the deck
  transform(base_deck, &deck_file);

  mix(&deck_file);

  distribute(&deck_file, deck_players, nb_players);	 

  first_tile(board, deck_players); //the first player play and put his first tile on the board randomly

  //Game loop
  int is_placed = 0;
  const struct tile *active_tile = empty_tile();

  while (skip < nb_players) {
    active_tile = pop(&deck_players[active_player]);
    is_placed = tile_placement(active_tile, board, board_size);
    if (is_placed == 0) {
      skip++;
      push(&deck_players[active_player], active_tile);
    }
    else {
      if (top(&deck_players[active_player]) == NULL)
	skip = nb_players;
      else
	skip = 0;
    }
    active_player = (active_player + 1) % nb_players;  //update the player
  }

  //Leaderboard
  int leaderboard[MAX_PLAYERS] = {};
  for (int i = 0; i < nb_players; i++)
    leaderboard[i]=deck_players[i].size;
  int player_min = 0;
  for (int j = 0; j < nb_players; j++) {
    for (int i = 0; i < nb_players; i++)
      if (leaderboard[i] < leaderboard[player_min])
	player_min = i;
    printf("Le joueur %d\t est arrivé %d\t ième avec %d\t tuile(s) restante(s)\n",
	   player_min + 1, j + 1, leaderboard[player_min]);
    leaderboard[player_min] = MAX_SIZE_FILE + 1;
  }

  return EXIT_SUCCESS;
}
