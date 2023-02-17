#include "../sqlite/sqlite3.h"
#include <stdio.h>
#include <string.h>
#include "./header.h"

int	place(int a, int b)
{
	sqlite3 *db;
	char *err_msg = 0;

	//requete
	char sql1[100] = "UPDATE Place SET  = ";
	char sql2 = (char) a;
	strcat(sql1, &sql2);
	char sql3[100] = " WHERE ";
	strcat(sql1, sql3);
	char sql4[100] = "Id = ";
	strcat(sql1, sql4);
	char sql5 = (char) b;
	strcat(sql1, &sql5);

	int rc = sqlite3_open("parking.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return (1);
	}

	// char *sql = "DROP TABLE IF EXISTS Cars;"
	// 			"CREATE TABLE Cars(Id INT, Name TEXT, Price INT);"
	// 			"INSERT INTO Cars VALUES(1, 'Audi', 52642);"
	// 			"INSERT INTO Cars VALUES(2, 'Mercedes', 57127);"
	// 			"INSERT INTO Cars VALUES(3, 'Skoda', 9000);"
	// 			"INSERT INTO Cars VALUES(4, 'Volvo', 29000);"
	// 			"INSERT INTO Cars VALUES(5, 'Bentley', 350000);"
	// 			"INSERT INTO Cars VALUES(6, 'Citroen', 21000);"
	// 			"INSERT INTO Cars VALUES(7, 'Hummer', 41400);"
	// 			"INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);";
	printf("%s", sql1);
	// rc = sqlite3_exec(db, sql1, 0, 0, &err_msg);

	// if (rc != SQLITE_OK)
	// {
	// 	fprintf(stderr, "SQL error: %s\n", err_msg);

	// 	sqlite3_free(err_msg);
	// 	sqlite3_close(db);

	// 	return (1);
	// }

	sqlite3_close(db);

	return (0);
}