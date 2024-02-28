//bindParameter.c
#include "method.h"

int bindCharParameters(sqlite3_stmt* stmt, char* name, int parameterIndex) {
    int rc; // SQLite �Լ� ȣ�� ����� �����ϴ� ����

    rc = sqlite3_bind_text(stmt, parameterIndex, name, -1, SQLITE_STATIC); // SQLite ���� ���ڿ� ���ε�

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to bind string parameter \n");
        return 1;
    }

    return 0;
}

int bindNumParameters(sqlite3_stmt* stmt, int num, int parameterIndex) {
    int rc; // SQLite �Լ� ȣ�� ����� �����ϴ� ����


    rc = sqlite3_bind_int(stmt, parameterIndex, num); // SQLite ���� ���ڿ� ���ε�


    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to bind num parameter \n");
        return 1;
    }

    return 0;
}

int handleSQLiteError(sqlite3* db, int rc, const char* message) {
    fprintf(stderr, "%s: %s\n", message, sqlite3_errmsg(db)); // �����޽��� ���
    sqlite3_close(db);
    return 1;
}