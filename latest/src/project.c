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
static int board = 10;

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

//trasnform a deck of deck_pair into a file with all the tiles
void transform(struct deck d, struct file* f)
{
  for (unsigned int i = 0 ; i < d.size ; i++){
    for  (unsigned int j = 0 ; j < d.cards[i].n ; j++){
      push(f, d.cards[i].t);
    }
  }
}

//return the positive int associate to his pointer and return -1 if the pointer is NULL
int ptoi(const int *i) 
{
  if (i == NULL)
    return -1;       
  return *i;
}

int main(int argc,  char* argv[])
{
  //each player is represented by a number
  int player1 = 0;
  int player2 = 1;
  int player3 = 2;
  int player4 = 3;
  int player5 = 4;
  int player6 = 5;
  int player7 = 6;
  int player8 = 7;
  int player9 = 8;
  int player10 = 9;
  int player11 = 10;
  int player12 = 11;
  int player13 = 12;
  int player14 = 13;
  int player15 = 14;
  int player16 = 15;
  int player17 = 16;
  int player18 = 17;
  int player19 = 18;
  int player20 = 19;

  int *players[20] = {&player1, &player2, &player3, &player4, &player5, &player6, &player7, &player8, &player9, &player10, &player11, &player12, &player13, &player14, &player15, &player16, &player17, &player18, &player19, &player20};

  struct file deck_players[MAX_PLAYERS] = {}; //a tabular that represent the decks of the players
  
  parse_opts(argc, argv);
  printf("Number of players : %d\n", nb_players);
  printf("Size of the board : %d\n", board);
  printf("Seed : %d\n", seed);
  
  //Initialization of the game
  struct deck base_deck = {};
  struct file deck_file = {};
  struct file player_file = {};
  
  deck_init(&base_deck);   //initialization of the deck
  transform(base_deck, &deck_file);

  for (int i = 0; i < nb_players; i++)
    push(&player_file, players[i]);     //initialization of the file of players used for the determination of the active player

  mix(&player_file);
  mix(&deck_file);

  distribute(&deck_file, deck_players, nb_players);	 

  //création du plateau de jeu 50*50 (pointeur NULL)
  //fonction qui prend entier un plateau et un pointeur vers une tuile et nous place la tuile sur la première case libre respectant les conditions
  //création de la boucle de jeu
  

  return EXIT_SUCCESS;
}
