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
	sz = snprintf(NULL, 0, "SELECT Place FROM Place WHERE Id = %d", a);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "SELECT Place FROM Place WHERE Id = %d", a);
	//work
	rc = sqlite3_open("../sqlite/parking.db", &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return (1);
	}
	printf("%s\n", sql);
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

	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return (0);
}