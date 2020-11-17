#include <stdio.h>
#include <string.h>
#include "color.h"
#include "tile.h"

int main(int argc, char *argv[])
{
	printf("\n");

	printf("Tests sur la structure color\n");
	printf("Est ce que color_from_name / color_name / color_cstring fonctionnent ?\n"); 
	printf("\n");
	
	printf("Voici 'rouge' écrit en rouge %s\n", color_cstring(color_from_name("rouge")));
	printf("la couleur correspondant à red est : %s\n", color_name(color_from_name("rouge")));

	printf("Voici 'bleu' écrit en bleu %s\n", color_cstring(color_from_name("bleu")));
	printf("la couleur correspondant à blue est : %s\n", color_name(color_from_name("bleu")));

	printf("Voici 'vert' écrit en vert %s\n", color_cstring(color_from_name("vert")));
	printf("la couleur correspondant à green est : %s\n", color_name(color_from_name("vert")));
	printf("\n");

	printf("Tests sur la structure tile\n");
	printf("Est ce que tile_is_empty / empty_tile fonctionnent ?\n");
	printf("\n");

	printf("Est ce qu'une tuile vide est vide : %s\n", tile_is_empty(empty_tile())?"oui":"non");
	printf("\n");

	printf("Est ce que tile_equals fonctionne avec des tuiles vides : %s\n",
		   tile_equals(empty_tile(), empty_tile())?"oui":"non");
	
	return 0;
}
