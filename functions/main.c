#include "../sqlite/sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char choix[100];
	char ident[100];
	char livre[100];
	int boo = 1;

	while (boo == 1)
	{
		printf("Menu : \n");
		printf("1 - Affecter une nouvelle place : \n");
		printf("=> ");
		scanf("%s", choix);

		switch (atoi(choix))
		{
		case 1:
			printf("Le type de place(1,2,3)\n");
			printf("1 - Véhicule \n");
			printf("2 - Moto \n");
			printf("3 - Camion \n");
			printf("=> ");
			scanf("%s", livre);
			place(atoi(livre));
			break ;
		}

		printf("Voulez-vous continuer ? (0 ou 1) \n");
		printf("=> ");
		scanf("%d", &boo);
	}
	return (0);
}