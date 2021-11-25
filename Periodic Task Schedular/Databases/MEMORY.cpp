//
//  MEMORY.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include "MEMORY.hpp"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sqlite3.h>
#include "Common.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


void createMemoryTable() {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("PTS.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   }
    
    /* Create SQL statement */
    sql = "CREATE TABLE MEMORY("  \
       "ID INT PRIMARY     KEY     NOT NULL," \
       "MemoryUsage        INT     NOT NULL);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "MEMORY Table created successfully\n");
    }
    sqlite3_close(db);
}

void insertIntoMemoryTable(std::string memoryUsage){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc, id;
    std::string sql;

   /* Open database */
   rc = sqlite3_open("PTS.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   }
    
    // finding the number of rows in table.
    id = getNumberOfRows("MEMORY");
    if(id == -1) {
        return;
    }
    id = id + 1;
    
    /* Create SQL statement */
    sql = "INSERT INTO MEMORY (ID,MemoryUsage) "  \
          "VALUES ( " + std::to_string(id) + ", " + memoryUsage + " );";
    

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
}
