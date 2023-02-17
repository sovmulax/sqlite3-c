#include "../sqlite/sqlite3.h"
#include "./header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Id, Place, aaa, bbb;
int	callback(void *, int, char **, char **);
int	callback2(void *, int, char **, char **);
int	verif(int a);

int	place(int az)
{
	sqlite3 *db;
	char *err_msg = 0;

	//requete
	char *sql;
	size_t sz;
	verif(az);
	sz = snprintf(NULL, 0, "UPDATE Place SET Place = %d WHERE Id = %d;", aaa, bbb);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "UPDATE Place SET Place = %d WHERE Id = %d;", aaa, bbb);

    //others
	int rc = sqlite3_open("../sqlite/parking.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return (1);
	}

	printf("%s\n", sql);

	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

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

int	verif(int a)
{
	sqlite3	*db;
	char	*err_msg;
	char	*sql;
	char	*sql2;
	size_t	sz;
	size_t	sz2;
	int		rc;
	int		rc2;

	err_msg = 0;
	//requete
	sz = snprintf(NULL, 0, "SELECT Id ,Place FROM Place WHERE Id = %d", a);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "SELECT Id ,Place FROM Place WHERE Id = %d", a);
	
    //requete 2
	sz2 = snprintf(NULL, 0, "SELECT Id ,Place FROM Place WHERE Id = 3");
	sql2 = (char *)malloc(sz2 + 1);
	snprintf(sql2, sz2 + 1, "SELECT Id ,Place FROM Place WHERE Id = 3");

	//work
	rc = sqlite3_open("../sqlitE/parking.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return (1);
	}

	rc2 = sqlite3_exec(db, sql2, callback2, 0, &err_msg);
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

int callback2(void *NotUsed, int argc, char **argv, char **azColName)
{
    Id = atoi(argv[0]);
    Place = atoi(argv[1]);
    return 0;
}


int	callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	NotUsed = 0;
	switch (atoi(argv[0]))
	{
	case 1:
		if (atoi(argv[1]) >= 6)
		{
			if (Place >= 4)
			{
				fprintf(stderr, "Il n'y a plus de place disponible\n");
			}
			else
			{
				//ajout d'une voiture chez les camions
                aaa = Place + 1 ;
                bbb = 3;
				//place(nb, 3);
				fprintf(stderr, "Cette voiture à été affecter chez les camions\n");
			}
		}
		else
		{
            aaa = atoi(argv[1]) + 1;
            bbb = 1;
		}
		break ;
	case 2:
		if (atoi(argv[1]) >= 6)
		{
			fprintf(stderr, "Il n'y a plus de place disponible\n");
		}
		else
		{
            aaa = atoi(argv[1]) + 1;
            bbb = 2;
			//place(nb, 2);
		}
		break ;
	case 3:
		if (atoi(argv[1]) >= 6)
		{
			fprintf(stderr, "Il n'y a plus de place disponible\n");
		}
		else
		{
            aaa = atoi(argv[1]) + 1;
            bbb = 3;
			//place(nb, 3);
		}
		break ;
	}

	return (0);
}