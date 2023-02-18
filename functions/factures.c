#include "sqlite3.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	callbacks(void *, int, char **, char **);

int	factures(int a, int b)
{
	sqlite3	*db;
	char	*err_msg;
	char	*sql;
	char	*sql2;
	size_t	sz;
	size_t	sz2;
	int		rc;
	int		rc2;
	int		price;
	char	*type;

	//calcule du prix
	switch (a)
	{
	case 1:
		price = b * 500;
		type = "Vehicule";
		break;
	case 2:
		price = b * 200;
		type = "Moto";
		break;
	case 3:
		price = b * 1000;
		type = "Camion";
		break;
	}

	err_msg = 0;
	//requete
	sz = snprintf(NULL, 0, "INSERT INTO Factures(vehicule, price) VALUES('%s', %d)", type, price);
	sql = (char *)malloc(sz + 1);
	snprintf(sql, sz + 1, "INSERT INTO Factures(vehicule, price) VALUES('%s', %d)", type, price);

	sz2 = snprintf(NULL, 0, "SELECT * FROM Factures WHERE Id in (select max(Id) from factures)");
	sql2 = (char *)malloc(sz2 + 1);
	snprintf(sql2, sz2 + 1, "SELECT * FROM Factures WHERE Id in (select max(Id) from factures)");
	
	//work
	rc = sqlite3_open("./parking.db", &db);
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

	rc2 = sqlite3_exec(db, sql2, callbacks, 0, &err_msg);

	if (rc2 != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return (1);
	}

	sqlite3_close(db);
	
	place(a, 1);
	
	return (0);
}

int	callbacks(void *NotUsed, int argc, char **argv, char **azColName)
{
	NotUsed = 0;

	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return (0);
}