#include <stdio.h>
#include <stdlib.h>

#include "dbconnect.h"

int main(int argc, char* argv[]) {

    insightLogin("postgres", "password");
    exit_nicely(conn);
    return 0;
}

void insightLogin(char* user, char* pass) {
    char conninfo[250];

    sprintf(conninfo, "user=%s password=%s dbname=%s hostaddr=%s port=%d", user, pass, PG_DB, PG_HOST, PG_PORT);

    //Start Connection
    conn = PQconnectdb(conninfo);

    if(PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "ERROR: Connection to database failed: %s", PQerrorMessage(conn));
        exit_nicely(conn);
    }
}
    
