#include "../sqlite/sqlite3.h"
#include "./header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	callback(void *, int, char **, char **);

int	verif(int a)
{
	sqlite3	*db;
	char	*err_msg;
	char	*sql;
	size_t	sz;
	int		rc;

	err_msg = 0;
	//requete
	sz = snprintf(NULL, 0, "SELECT Id ,Place FROM Place WHERE Id = %d and Id = 3", a);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "SELECT Id ,Place FROM Place WHERE Id = %d and Id = 3", a);
	//work
	rc = sqlite3_open("../sqlitE/parking.db", &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return (1);
	}
	rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return (1);
	}
	sqlite3_close(db);
	return (0);
}

int	callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	NotUsed = 0;
	int nb;

	printf("i %s\n", argv[0]);
	printf("n %s\n", argv[1]);

	switch (atoi(argv[0]))
	{
	case 1:
		if (atoi(argv[1]) >= 6)
		{
			if (atoi(argv[3]) >= 4)
			{
				fprintf(stderr, "Il n'y a plus de place disponible\n");
			}
			else
			{
				//ajout d'une voiture chez les camions
				int nb = atoi(argv[3]) + 1;
				place(nb, atoi(argv[2]));
				fprintf(stderr, "Cette voiture à été affecter chez les camions\n");
			}
		}
		else
		{
			int nb = atoi(argv[1]) + 1;
			place(nb, atoi(argv[0]));
		}
	case 2:
		if (atoi(argv[1]) >= 6)
		{
			fprintf(stderr, "Il n'y a plus de place disponible\n");
		}
		else
		{
			int nb = atoi(argv[1]) + 1;
			place(nb, atoi(argv[0]));
		}
	case 3:
		if (atoi(argv[1]) >= 6)
		{
			fprintf(stderr, "Il n'y a plus de place disponible\n");
		}
		else
		{
			int nb = atoi(argv[1]) + 1;
			place(nb, atoi(argv[0]));
		}
	}

	return (0);
}