//selectSale.c
#include "method.h"

int selectSale(char sigun_gu[20], char rent_type[20], int minPrice, int maxPrice, int minPyeong, int maxPyeong)
{

    sqlite3* db; // SQLite 데이터베이스 포인터 선언
    sqlite3_stmt* stmt; // SQLite의 상태를 나타내는 포인터 선언
    int parameterIndex = 1, count = 1, result = 0, choice = 0; // 바인딩에 필요한 인덱스, 검색 결과 개수를 저장할 변수
    int rc = sqlite3_open("test.db", &db); // SQLite 데이터베이스 열기
    extern int id[3000]; // 검색한 결과 id를 저장할 배열
    char tmp[200];

    // db가 잘 열렸는지 판단
    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Cannot open database");
    }
    else {
        sqlite3_exec(db, "PRAGMA encoding = 'UTF-8';", NULL, NULL, NULL);
    }

    // sql 실행
    char* sql = "SELECT id, b_name, b_dongnum, floor, sigun_gu, rent_type, price, pyeong FROM BUILDINGS WHERE sigun_gu = ? AND rent_type = ? AND price BETWEEN ? AND ? AND pyeong BETWEEN ? AND ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); // SQL 문을 준비하여 stmt에 저장

    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Failed to prepare statement");
    }

    // 바인딩 함수 호출
    if (bindCharParameters(stmt, sigun_gu, parameterIndex++) != 0) { // 첫 번째 바인딩 호출
        sqlite3_finalize(stmt); // SQLite 문 해제
        sqlite3_close(db); // 데이터베이스 닫기
        return 1; // 프로그램 종료
    }

    if (bindCharParameters(stmt, rent_type, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, minPrice, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, maxPrice, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, minPyeong, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, maxPyeong, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (sqlite3_step(stmt) != SQLITE_ROW) {
        printf("                                         >>> 조건에 부합하는 매물이 존재하지 않습니다. \n\n");
        return 0;
    }

    printf("-----------------------------------------------------------------------------------------------\n");
    printf(" %s    %15s        %5s    %3s    %5s      %5s    %5s     %5s \n",
        "번호", "건물명", "동번호", "층", "지역", "타입", "가격", "평수");
    printf("-----------------------------------------------------------------------------------------------\n");

    // 가져온 데이터를 한글로 출력하도록 변환
    setlocale(LC_ALL, "ko_KR.UTF-8");


    // SQL 문 실행 및 결과 처리
    while (sqlite3_step(stmt) == SQLITE_ROW && result <= 10) { // SQL 문 실행 및 결과가 있는 경우 (행 데이터 하나씩)
        int i;
        int num_cols = sqlite3_column_count(stmt); // 결과 집합의 열 수

        for (i = 0; i < num_cols; i++) { // 각 열에 대해 반복
            const unsigned char* col_value = sqlite3_column_text(stmt, i); // 열 값

            if (i == 0) {
                id[count] = atoi((const char*)col_value);
                printf("%3d ", count++);
                continue;
            }

            if (i == 1) {
                printf("%-30s ", col_value); //건물
                continue;
            }
            printf("%8s ", col_value);
        }
        printf("\n");
        result++;
        if (result == 10) {
            setlocale(LC_ALL, "C");
            do {
                printf("\n\n ▶▶       [1] 검색 결과 더보기               [2] 검색 종료 후 상세 정보 확인     \n\n  입력:  ");
                gets(tmp);
                choice = atoi(tmp);
            } while ((choice == 0 && tmp[0] != '0') || (choice != 1 && choice != 2));
            setlocale(LC_ALL, "ko_KR.UTF-8");
        }

        if (choice == 2) {
            break;
        }
        else if (choice == 1) {
            result = 0;
            choice = 0;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    // 작업이 끝나면 원래의 로케일로 복원
    setlocale(LC_ALL, "C");

    return --count;
}