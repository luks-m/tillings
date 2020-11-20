#include <stdio.h>
#include <string.h>
#include "color.h"
#include "tile.h"
#include "file.h"

void transform(struct deck d, struct file* f)
{
	for (unsigned int i = 0 ; i < d.size ; i++){
		for  (unsigned int j = 0 ; j < d.cards[i].n ; j++){
			push(f, d.cards[i].t);
		}
	}
}

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
	printf("\n");

	printf("On vérifie maintenant que notre deck est bien initialisé\n");
	struct deck base_deck = {};
	struct file deck_file = {};

	deck_init(&base_deck);
	printf("la couleur du triangle nord de la tuile associée a la première deck_pair est : %s\n", color_name( tile_edge(base_deck.cards[0].t, 0) ));
	printf("\n");
	
	printf("On test la fonction qui transforme un deck en file\n");
	transform(base_deck, &deck_file);
	
	printf("la couleur du triangle nord de la tuile dont l'adresse se trouve en tête de file est : %s\n", color_name( tile_edge( top(&deck_file), 0 )));
	print("\n");

	printf("On créé une file vide\n");
	struct file test_file = {};

	printf("On va tester top, pop et push, leurs cas d'utilisation normaux et limites\n");
	printf("On essaye de faire un top sur la liste vide, résultat : \n");
	printf("On fait push un 1 puis un 2 dans la file\n");
	printf("On fait un top et on trouve : \n");
	printf("On fait deux pop et on trouve : \n");
	prinf("La liste est normalement vide, on va pouvoir essayer un pop et on tombe sur : \n");
	
	
	
	return 0;
}
