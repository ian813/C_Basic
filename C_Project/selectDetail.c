//selectDetail.c
#include "method.h"

// 검색한 결과 id를 저장할 배열
extern int id[3000];

int selectDetail(int idx, int count, int rentType)
{

    sqlite3* db; // SQLite 데이터베이스 포인터 선언
    sqlite3_stmt* stmt; // SQLite의 상태를 나타내는 포인터 선언
    int parameterIndex = 1; // 바인딩에 필요한 인덱스 변수
    int rc = sqlite3_open("test.db", &db); // SQLite 데이터베이스 열기
    char* sql; // 쿼리문 저장

    // db가 잘 열렸는지 판단
    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Cannot open database");
    }
    else {
        sqlite3_exec(db, "PRAGMA encoding = 'UTF-8';", NULL, NULL, NULL);
    }

    // rentType에 따라 다른 쿼리문 실행 (보여줄 데이터가 다르므로)
    if (rentType == 1) {
        sql = "SELECT b_name, b_dongnum, floor, price, pyeong, direction, b_age, detail_tag1, detail_tag2, detail_tag3 FROM BUILDINGS WHERE id = ?";
    }
    else if (rentType == 2) {
        sql = "SELECT b_name, b_dongnum, floor, deposit, pyeong, direction, b_age, detail_tag1, detail_tag2, detail_tag3 FROM BUILDINGS WHERE id = ?";
    }
    else {
        sql = "SELECT b_name, b_dongnum, floor, deposit, fee, pyeong, direction, b_age, detail_tag1, detail_tag2, detail_tag3 FROM BUILDINGS WHERE id = ?";
    }
    

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); // SQL 문을 준비하여 stmt에 저장

    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Failed to prepare statement");
    }

    // 바인딩 함수 호출
    if (bindNumParameters(stmt, id[idx], parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    printf("\n-----------------------------------| %d번 건물에 대한 상세정보 |------------------------------------\n", idx);
    
    // 로케일을 한글을 출력하도록 변환
    setlocale(LC_ALL, "ko_KR.UTF-8");

    // SQL 문 실행 및 결과 처리
    while (sqlite3_step(stmt) == SQLITE_ROW) { // SQL 문 실행 및 결과가 있는 경우 (행 데이터 하나 가져옴)
        int i;
        int num_cols = sqlite3_column_count(stmt); // 결과 집합의 열 수

        for (i = 0; i < num_cols; i++) { // 각 열에 대해 반복
            //const unsigned char* col_name = sqlite3_column_name(stmt, i); // 열 이름
            const unsigned char* col_value = sqlite3_column_text(stmt, i); // 열 값

            setlocale(LC_ALL, "C");
            if(rentType == 1) {
                if (i == 0) {
                    printf("\n  건물이름 : ");
                }
                else if (i == 1) {
                    printf("  동번호 : ");
                }
                else if (i == 2) {
                    printf("  층 : ");
                }
                else if (i == 3) {
                    printf("  가격 : ");
                }
                else if (i == 4) {
                    printf("  평수 : ");
                }
                else if (i == 5) {
                    printf("  방향 : ");
                }
                else if (i == 6) {
                    printf("  연식 : ");
                }
                else if (i == 7) {
                    printf("  추가정보1 : ");
                }
                else if (i == 8) {
                    printf("  추가정보2 : ");
                }
                else if (i == 9) {
                    printf("  추가정보3 : ");
                }
            }
            else if (rentType == 2) {
                if (i == 0) {
                    printf("  건물이름 : ");
                }
                else if (i == 1) {
                    printf("  동번호 : ");
                }
                else if (i == 2) {
                    printf("  층 : ");
                }
                else if (i == 3) {
                    printf("  보증금 : ");
                }
                else if (i == 4) {
                    printf("  평수 : ");
                }
                else if (i == 5) {
                    printf("  방향 : ");
                }
                else if (i == 6) {
                    printf("  연식 : ");
                }
                else if (i == 7) {
                    printf("  추가정보1 : ");
                }
                else if (i == 8) {
                    printf("  추가정보2 : ");
                }
                else if (i == 9) {
                    printf("  추가정보3 : ");
                }
            }
            else {
                if (i == 0) {
                    printf("  건물이름 : ");
                }
                else if (i == 1) {
                    printf("  동번호 : ");
                }
                else if (i == 2) {
                    printf("  층 : ");
                }
                else if (i == 3) {
                    printf("  보증금 : ");
                }
                else if (i == 4) {
                    printf("  월세 : ");
                }
                else if (i == 5) {
                    printf("  평수 : ");
                }
                else if (i == 6) {
                    printf("  방향 : ");
                }
                else if (i == 7) {
                    printf("  연식 : ");
                }
                else if (i == 8) {
                    printf("  추가정보1 : ");
                }
                else if (i == 9) {
                    printf("  추가정보2 : ");
                }
                else if (i == 10) {
                    printf("  추가정보3 : ");
                }
            }

            setlocale(LC_ALL, "ko_KR.UTF-8");
            printf("%-s \n", col_value);
        }

        printf("\n");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);


    // 작업이 끝나면 원래의 로케일로 복원
    setlocale(LC_ALL, "C");

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\n  다른 매물에 대한 상세정보도 보고 싶다면?? \n");

    return 0;
}