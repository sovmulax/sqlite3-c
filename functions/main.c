#include "../sqlite/sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char *choix;
	char ident[100];
	char livre[100];

	printf("Menu : \n");
	printf("1 - Liste de livre : \n");
	//scanf("Choix %s", choix);
	choix = "1";

	switch (atoi(choix))
	{
	case 1:
		printf("la Place ");
		scanf("%s", ident);

		printf("L'id de la place ");
		scanf("%s", livre);

		place(atoi(ident), atoi(livre));
		break ;
	}

	return (0);
}