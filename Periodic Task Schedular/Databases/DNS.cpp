//
//  DNS.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include "DNS.hpp"
#include "Common.hpp"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void createDnsTable() {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test7.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   }

   /* Create SQL statement */
   sql = "CREATE TABLE DNS("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "DnsResolveTime INT     NOT NULL);";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "DNS Table created successfully\n");
   }
   sqlite3_close(db);
}

void insertIntoDnsTable(std::string dnsResolveTime){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc, id;
   std::string sql;

   /* Open database */
   rc = sqlite3_open("test7.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   }
    
   // finding the number of rows in table.
   id = getNumberOfRows("DNS");
    if(id == -1) {
        return;
    }
    id = id + 1;
    std::cout << id << ":: " << dnsResolveTime << std::endl;
   /* Create SQL statement */
   sql = "INSERT INTO DNS (ID,DnsResolveTime) "  \
         "VALUES ( " + std::to_string(id) + ", " + dnsResolveTime + " );";
    std::cout << sql << std::endl;
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Inserted into DNS table successfully\n");
   }
   sqlite3_close(db);
}

