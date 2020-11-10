#include <stdio.h>
#include <string.h>
#include "color.h"
#include "tile.h"

int main(int argc, char *argv[])
{
	printf("Tests sur la structure color\n");
	printf("Est ce que le programme vérifie bien qu'une couleur est valide avant d'en donner le nom ou le code ANSI ? ");
	struct color invalide = {"testcode", "pasunecouleur"};
	printf("la couleur correspondant à red est : %s\n", color_name(&red));
	printf("la couleur correspondant à invalide est : %s\n", color_name(&invalide));
	printf("le code ANSI correspondant à red est : %s\n", color_cstring(&red));
	printf("la cde ANSI correspondant à invalide est : %s\n", color_cstring(&invalide));
	printf("\n");
	printf("On verifie que le pointeur retourné par color_from_name est valide");
	struct color* bleu = color_from_name("bleu");
	printf("la couleur correspondant à bleu est : %s", bleu->name);
	printf("le code ANSI correspondant à bleu est : %s", bleu->ANSI);
	return 0;
}
