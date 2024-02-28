//bindParameter.c
#include "method.h"

int bindCharParameters(sqlite3_stmt* stmt, char* name, int parameterIndex) {
    int rc; // SQLite 함수 호출 결과를 저장하는 변수

    rc = sqlite3_bind_text(stmt, parameterIndex, name, -1, SQLITE_STATIC); // SQLite 문에 문자열 바인딩

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to bind string parameter \n");
        return 1;
    }

    return 0;
}

int bindNumParameters(sqlite3_stmt* stmt, int num, int parameterIndex) {
    int rc; // SQLite 함수 호출 결과를 저장하는 변수


    rc = sqlite3_bind_int(stmt, parameterIndex, num); // SQLite 문에 문자열 바인딩


    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to bind num parameter \n");
        return 1;
    }

    return 0;
}

int handleSQLiteError(sqlite3* db, int rc, const char* message) {
    fprintf(stderr, "%s: %s\n", message, sqlite3_errmsg(db)); // 오류메시지 출력
    sqlite3_close(db);
    return 1;
}