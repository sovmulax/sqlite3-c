#include "../sqlite/sqlite3.h"
#include "./header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	verif(int a, int b)
{
	sqlite3 *db;
	char *err_msg = 0;

	//requete
	char *sql;
	size_t sz;
	sz = snprintf(NULL, 0, "UPDATE Place SET place = %d WHERE Id = %d;", a, b);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "UPDATE Place SET place = %d WHERE Id = %d;", a, b);

    //others
	int rc = sqlite3_open("../sqlite/parking.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return (1);
	}

	printf("%s", sql);

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