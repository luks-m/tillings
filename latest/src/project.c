#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

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
      players = atoi(optarg);
      break;
    case 'b':
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
int main(int argc,  char* argv[])
{
  parse_opts(argc, argv);
  printf("Number of players : %d\n", players);
  printf("Size of the board : %d\n", board);
  printf("Seed : %d\n", seed);
  return EXIT_SUCCESS;
}
