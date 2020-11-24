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

//trasnform a deck of deck_pair into a file with all the tiles
void transform(struct deck d, struct file* f)
{
	for (unsigned int i = 0 ; i < d.size ; i++)
		for  (unsigned int j = 0 ; j < d.cards[i].n ; j++)
			push(f, d.cards[i].t);
}

//return the positive int associate to his pointer and return -1 if the pointer is NULL
int ptoi(const int *i) 
{
  if (i == NULL)
    return -1;       
  return *i;
}

void first_tile(const struct tile* b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], struct file f_hand[])
{
	int first_player = 0;
	b[rand()%board_size][rand()%board_size] = pop(&f_hand[first_player]);
}

int test_position(const struct tile* b[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int x, int y, struct tile* t);

int main(int argc,  char* argv[])
{

  struct file deck_players[MAX_PLAYERS] = {}; //a tabular that represent the decks of the players

  const struct tile* board[MAX_SIZE_BOARD][MAX_SIZE_BOARD] = {};
  
  parse_opts(argc, argv);
  printf("Number of players : %d\n", nb_players);
  printf("Size of the board : %d\n", board_size);
  printf("Seed : %d\n", seed);
  
  //Initialization of the game
  struct deck base_deck = {};
  struct file deck_file = {};
  
  deck_init(&base_deck);   //initialization of the deck
  transform(base_deck, &deck_file);

  mix(&deck_file);

  distribute(&deck_file, deck_players, nb_players);	 

  first_tile(board, deck_players); //the first player play and put his first tile on the board randomly 

  //créer une fonction qui prend en argument une tuile et une position (x,y) et qui retourne 1 si on peut positionner la tuile, 0 si on ne peut pas
  
  //créer une fonction qui prend en arguement une tuile et le plateau de jeu et vérifie si la tuile est plaçable, si c'est le cas elle retourne 1 et place la tuile sur le plateau ; sinon elle retourne 0 et place la tuile du joueur en dessous de son paquet
  
  //ona  une variable qui compte le nombre de skip d'affilé et qui arrête le jeu si elle vaut nb_players et qui reviens a 0 si un joueur arrive a placer une tuile

  return EXIT_SUCCESS;
}
