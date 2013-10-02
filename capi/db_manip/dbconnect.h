#include           <stdlib.h>
#include           <libpq-fe.h>

#define PG_HOST    "127.0.0.1"
#define PG_DB      "postgres"
#define PG_PORT    5432

PGconn* conn;

static void exit_nicely(PGconn* conn) {
    PQfinish(conn);
    exit(1);
}    

void insightLogin(char* user, char* pass);
