#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "tile.h"
#include "color.h"
#include "file.h"


//Global number of players
static int players = 2;

//Global size of the board
static int board = 50;

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
		if (atoi(optarg) > 20) {
			fprintf(stderr, "Usage: %s [-n number of players <= 20]\n",
					argv[0]);
			exit(EXIT_FAILURE);		
		}
		players = atoi(optarg);
		break;
    case 'b':
		if (atoi(optarg) > 50) {
			fprintf(stderr, "Usage: %s [-b size of the board <= 50]\n",
					argv[0]);
			exit(EXIT_FAILURE);		
		}
		board = atoi(optarg);
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

void transform(struct deck d, struct file* f)
{
	for (unsigned int i = 0 ; i < d.size ; i++){
		for  (unsigned int j = 0 ; j < d.cards[i].n ; j++){
			push(f, d.cards[i].t);
		}
	}
}

int main(int argc,  char* argv[])
{
  parse_opts(argc, argv);
  printf("Number of players : %d\n", players);
  printf("Size of the board : %d\n", board);
  printf("Seed : %d\n", seed);
  
  //Initialization of the game
  struct deck base_deck = {};
  struct file deck_file = {};
  
  deck_init(&base_deck);
  printf("%s\n", color_name( tile_edge(base_deck.cards[0].t, 0) ));

  transform(base_deck, &deck_file);
  printf("%s\n", color_name( tile_edge( deck_file.queue[0], 0 )));
  

  return EXIT_SUCCESS;
}
