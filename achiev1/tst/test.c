#include <stdio.h>
#include <string.h>
#include "color.h"
#include "tile.h"
#include "file.h"
#include "board.h"
#include "pattern.h"

int ptoi(const int *i) //return the positive int associate to his pointer
{
  if (i == NULL)
    return -1;
  return *i;
}

void transform(struct deck d, struct file* f)
{
  for (unsigned int i = 0 ; i < d.size ; i++){
    for  (unsigned int j = 0 ; j < d.cards[i].n ; j++){
      push(f, d.cards[i].t);
    }
  }
}

int main()
{
  printf("\n");

  printf("Tests sur la structure color\n");
  printf("Est ce que color_from_name / color_name / color_cstring fonctionnent ?\n"); 
  printf("\n");
	
  printf("Voici 'R' écrit en rouge %s\n", color_cstring(color_from_name("red")));
  printf("la couleur correspondant à red est : %s\n", color_name(color_from_name("red")));

  printf("Voici 'B' écrit en bleu %s\n", color_cstring(color_from_name("blue")));
  printf("la couleur correspondant à blue est : %s\n", color_name(color_from_name("blue")));

  printf("Voici 'V' écrit en vert %s\n", color_cstring(color_from_name("green")));
  printf("la couleur correspondant à green est : %s\n", color_name(color_from_name("green")));
  printf("\n");

  printf("Tests sur la structure tile\n");
  printf("Est ce que tile_is_empty / empty_tile fonctionnent ?\n");
  printf("\n");

  printf("Est ce qu'une tuile vide est vide : %s\n", tile_is_empty(empty_tile())?"oui":"non");
  printf("\n");

  printf("Est ce que tile_equals fonctionne avec des tuiles vides : %s\n",
	 tile_equals(empty_tile(), empty_tile())?"oui":"non");
  printf("\n");

  printf("On vérifie maintenant que notre deck est bien initialisé\n");
	
  //Initialization of an empty deck_pair
  unsigned int n_init = 0;
  const struct tile* t_init = empty_tile();
  struct deck_pair pair_init = {t_init, n_init};

  //Initialization of an empty deck
  struct deck deck_test;
  for (int i = 0 ; i < MAX_DECK_SIZE; i++)
    deck_test.cards[i] = pair_init;
  deck_test.size = 0;
	
  //Initialization of en empty file
  struct file deck_file;
  for (int i = 0 ; i < MAX_SIZE_FILE ; i++)
    deck_file.queue[i] = NULL;
  deck_file.size = 0;

  deck_init(&deck_test);
  printf("la couleur du triangle nord de la tuile associée a la première deck_pair est rouge ? %s\n", (strcmp(color_name(tile_edge(deck_test.cards[0].t, 0)),"red")==0)?"oui":"non");
  printf("\n");
	
  printf("On test la fonction qui transforme un deck en file\n");
  transform(deck_test, &deck_file);
	
  printf("la couleur du triangle nord de la tuile dont l'adresse se trouve en tête de file est rouge ? %s\n", (strcmp(color_name(tile_edge(top(&deck_file), 0 )),"red")==0)?"oui":"non");
  printf("\n");

  printf("On créé une file vide\n");
	
  //Initialization of en empty file
  struct file test_file;
  for (int i = 0 ; i < MAX_SIZE_FILE ; i++)
    test_file.queue[i] = NULL;
  test_file.size = 0;
	
  printf("La taille de la file est actuellement : %d\n", test_file.size);
  int un = 1;
  int deux = 2;
  printf("On va tester top, pop et push, leurs cas d'utilisation normaux et limites\n");
  printf("On essaye de faire un top sur la liste vide, résultat : %d\n",
	 ptoi(top(&test_file)));
  printf("On push deux entiers (1 puis 2) dans la file\n");
  push(&test_file, &un);
  push(&test_file, &deux);
  printf("On fait un top et on trouve : %d\n", ptoi(top(&test_file)));
  printf("On fait deux pop et on trouve : %d", ptoi(pop(&test_file)));
  printf(" puis %d\n", ptoi(pop(&test_file)));
  printf("La liste est normalement vide, on va pouvoir essayer un pop et on tombe sur : %d \n",ptoi(pop(&test_file))) ;
  printf("\n");

  printf("On va maintenant effectuer des tests sur les motifs\n");
  printf("\n");
 
  //Initialization of boards, each will contains a different pattern 
  struct board_cell board_pattern1[MAX_SIZE_BOARD][MAX_SIZE_BOARD];

  struct board_cell board_pattern2[MAX_SIZE_BOARD][MAX_SIZE_BOARD];

  struct board_cell board_pattern7[MAX_SIZE_BOARD][MAX_SIZE_BOARD];

  for (int y = 0; y < 3; y++)
    for (int x = 0; x < 3; x++){
      change_tile(board_pattern1, x, y, empty_tile());
	  change_tile(board_pattern2, x, y, empty_tile());
	  change_tile(board_pattern7,x, y, empty_tile());
	}
  
  //Initialization of the used tiles in this test
  const struct tile* center = deck_test.cards[0].t; //full red tile
  const struct tile* up = deck_test.cards[14].t; //tile with red at south
  const struct tile* down = deck_test.cards[15].t; // tile with red at north
  const struct tile* right = deck_test.cards[12].t; //tile with red at west
  const struct tile* left = deck_test.cards[12].t; //tile with red at east

  //Fill the boards with tiles to create patterns

  change_tile(board_pattern1, 1, 1, center);
  change_tile(board_pattern2, 1, 1, center);
  change_tile(board_pattern7, 1, 1, center);
  
  change_tile(board_pattern1, 1, 0, up);
  change_tile(board_pattern2, 1, 0, up);

  change_tile(board_pattern1, 1, 2, down);
  change_tile(board_pattern2, 1, 2, down);
  change_tile(board_pattern7, 1, 2, down);
  
  change_tile(board_pattern1, 2, 1, right);
  change_tile(board_pattern7, 2, 1, right);

  change_tile(board_pattern1, 0, 1, left);

  //test the pattern functions
  printf("Voici board_pattern1");
  draw_board(board_pattern1, 3);
  printf("\n");
  
  printf("Le pattern 1 est-il bien trouvé dans board_pattern1 : %s\n",
		 (pattern1(board_pattern1, 1, 1))?"oui":"non");
  printf("\n");

  printf("Voici board_pattern2");
  draw_board(board_pattern2, 3);
  printf("\n");
  
  printf("Le pattern 2 est-il bien trouvé dans board_pattern2 : %s\n",
		 (pattern2(board_pattern2, 1, 1))?"oui":"non");
  printf("\n");
  
  printf("Voici board_pattern4");
  draw_board(board_pattern7, 3);
  printf("\n");
  
  printf("Le pattern 7 est-il bien trouvé dans board_pattern7 : %s\n",
		 (pattern7(board_pattern7, 1, 1))?"oui":"non");
  printf("\n");
  
  printf("Le pattern 1 non présent dans board_pattern7 est-il trouvé : %s\n",
		 (pattern1(board_pattern7, 1, 1))?"oui":"non");
  printf("\n");


  return 0;
}
