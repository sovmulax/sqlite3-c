#include "header.h"
#include <stdio.h>

int	main(void)
{
	char * choix;
	char nom[100];
	char livre[100];
	char auteur[100];
	char id[100];
	printf("Menu : \n");
	printf("1 - Liste de livre : \n");
	scanf("Choix %s\n", choix);

	switch (choix)
	{
	case 1:
		scanf("Id %s\n", id);
		scanf("Type %s\n", livre);
		place(atoi(id), atoi(livre));
		break ;
	}

	return (0);
}