//
//  Common.cpp
//  Periodic Task Schedular
//
//  Created by Bir Bahadur Khatri on 24/11/2021.
//

#include "Common.hpp"
#include "DNS.hpp"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sqlite3.h>


static int callback1(void *count, int argc, char **argv, char **azColName) {
    int *c =(int*) count;
    *c = atoi(argv[0]);
    return 0;
}

static int callback2(void *value, int argc, char **argv, char **azColName) {
    float *c =(float*) value;
    *c = atoi(argv[0]);
    return 0;
}

int getNumberOfRows(std::string table) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc, count = -1;
    std::string sql;

    /* Open database */
    rc = sqlite3_open("test7.db", &db);
    
    if( rc ) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    /* Create SQL statement */
    sql = "SELECT COUNT(*) FROM "+ table;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback1, &count, &zErrMsg);
    
    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return count;
}

float getValue(std::string table, std::string column, std::string command) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    float value = -1.0;
    std::string sql;

    /* Open database */
    rc = sqlite3_open("test7.db", &db);

    if( rc ) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
       return -1.0;
    }

    /* Create SQL statement */
    sql = "SELECT " + command + "( " + column + " ) FROM "+ table;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback2, &value, &zErrMsg);

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return value;
}

void initialize() {
    createDnsTable();
}
