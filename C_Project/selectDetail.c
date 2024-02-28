//selectDetail.c
#include "method.h"

// �˻��� ��� id�� ������ �迭
extern int id[3000];

int selectDetail(int idx, int count, int rentType)
{

    sqlite3* db; // SQLite �����ͺ��̽� ������ ����
    sqlite3_stmt* stmt; // SQLite�� ���¸� ��Ÿ���� ������ ����
    int parameterIndex = 1; // ���ε��� �ʿ��� �ε��� ����
    int rc = sqlite3_open("test.db", &db); // SQLite �����ͺ��̽� ����
    char* sql; // ������ ����

    // db�� �� ���ȴ��� �Ǵ�
    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Cannot open database");
    }
    else {
        sqlite3_exec(db, "PRAGMA encoding = 'UTF-8';", NULL, NULL, NULL);
    }

    // rentType�� ���� �ٸ� ������ ���� (������ �����Ͱ� �ٸ��Ƿ�)
    if (rentType == 1) {
        sql = "SELECT b_name, b_dongnum, floor, price, pyeong, direction, b_age, detail_tag1, detail_tag2, detail_tag3 FROM BUILDINGS WHERE id = ?";
    }
    else if (rentType == 2) {
        sql = "SELECT b_name, b_dongnum, floor, deposit, pyeong, direction, b_age, detail_tag1, detail_tag2, detail_tag3 FROM BUILDINGS WHERE id = ?";
    }
    else {
        sql = "SELECT b_name, b_dongnum, floor, deposit, fee, pyeong, direction, b_age, detail_tag1, detail_tag2, detail_tag3 FROM BUILDINGS WHERE id = ?";
    }
    

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); // SQL ���� �غ��Ͽ� stmt�� ����

    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Failed to prepare statement");
    }

    // ���ε� �Լ� ȣ��
    if (bindNumParameters(stmt, id[idx], parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    printf("\n-----------------------------------| %d�� �ǹ��� ���� ������ |------------------------------------\n", idx);
    
    // �������� �ѱ��� ����ϵ��� ��ȯ
    setlocale(LC_ALL, "ko_KR.UTF-8");

    // SQL �� ���� �� ��� ó��
    while (sqlite3_step(stmt) == SQLITE_ROW) { // SQL �� ���� �� ����� �ִ� ��� (�� ������ �ϳ� ������)
        int i;
        int num_cols = sqlite3_column_count(stmt); // ��� ������ �� ��

        for (i = 0; i < num_cols; i++) { // �� ���� ���� �ݺ�
            //const unsigned char* col_name = sqlite3_column_name(stmt, i); // �� �̸�
            const unsigned char* col_value = sqlite3_column_text(stmt, i); // �� ��

            setlocale(LC_ALL, "C");
            if(rentType == 1) {
                if (i == 0) {
                    printf("\n  �ǹ��̸� : ");
                }
                else if (i == 1) {
                    printf("  ����ȣ : ");
                }
                else if (i == 2) {
                    printf("  �� : ");
                }
                else if (i == 3) {
                    printf("  ���� : ");
                }
                else if (i == 4) {
                    printf("  ��� : ");
                }
                else if (i == 5) {
                    printf("  ���� : ");
                }
                else if (i == 6) {
                    printf("  ���� : ");
                }
                else if (i == 7) {
                    printf("  �߰�����1 : ");
                }
                else if (i == 8) {
                    printf("  �߰�����2 : ");
                }
                else if (i == 9) {
                    printf("  �߰�����3 : ");
                }
            }
            else if (rentType == 2) {
                if (i == 0) {
                    printf("  �ǹ��̸� : ");
                }
                else if (i == 1) {
                    printf("  ����ȣ : ");
                }
                else if (i == 2) {
                    printf("  �� : ");
                }
                else if (i == 3) {
                    printf("  ������ : ");
                }
                else if (i == 4) {
                    printf("  ��� : ");
                }
                else if (i == 5) {
                    printf("  ���� : ");
                }
                else if (i == 6) {
                    printf("  ���� : ");
                }
                else if (i == 7) {
                    printf("  �߰�����1 : ");
                }
                else if (i == 8) {
                    printf("  �߰�����2 : ");
                }
                else if (i == 9) {
                    printf("  �߰�����3 : ");
                }
            }
            else {
                if (i == 0) {
                    printf("  �ǹ��̸� : ");
                }
                else if (i == 1) {
                    printf("  ����ȣ : ");
                }
                else if (i == 2) {
                    printf("  �� : ");
                }
                else if (i == 3) {
                    printf("  ������ : ");
                }
                else if (i == 4) {
                    printf("  ���� : ");
                }
                else if (i == 5) {
                    printf("  ��� : ");
                }
                else if (i == 6) {
                    printf("  ���� : ");
                }
                else if (i == 7) {
                    printf("  ���� : ");
                }
                else if (i == 8) {
                    printf("  �߰�����1 : ");
                }
                else if (i == 9) {
                    printf("  �߰�����2 : ");
                }
                else if (i == 10) {
                    printf("  �߰�����3 : ");
                }
            }

            setlocale(LC_ALL, "ko_KR.UTF-8");
            printf("%-s \n", col_value);
        }

        printf("\n");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);


    // �۾��� ������ ������ �����Ϸ� ����
    setlocale(LC_ALL, "C");

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\n  �ٸ� �Ź��� ���� �������� ���� �ʹٸ�?? \n");

    return 0;
}