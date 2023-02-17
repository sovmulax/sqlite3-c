#include "../sqlite/sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char choix[100];
	char ident[100];
	char livre[100];

	printf("Menu : \n");
	printf("1 - Affecter une nouvelle place : \n");
	printf("2 - Affecter une nouvelle place : \n");
	scanf("%s", choix);

	switch (atoi(choix))
	{
	case 1:
		printf("L'id de la place ");
		scanf("%s", livre);

		verif(atoi(livre));
		break ;

	//case 2:
		//printf("%d", verif(1));
		//verif(1);
	}

	return (0);
}