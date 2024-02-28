//selectMonthlyRent.c
#include "method.h"

// sigun_gu : ����1
// rent_type : ����2
int selectMonthlyRent(char sigun_gu[20], char rent_type[20], int minDeposit, int maxDeposit, int minFee, int maxFee, int minPyeong, int maxPyeong)
{

    sqlite3* db; // SQLite �����ͺ��̽� ������ ����
    sqlite3_stmt* stmt; // SQLite�� ���¸� ��Ÿ���� ������ ����
    int parameterIndex = 1, count = 1, result = 0, choice = 0; // ���ε��� �ʿ��� �ε���, �˻� ��� ������ ������ ����
    int rc = sqlite3_open("test.db", &db); // SQLite �����ͺ��̽� ����
    extern int id[3000]; // �˻��� ��� id�� ������ �迭
    char tmp[200];

    // db�� �� ���ȴ��� �Ǵ�
    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Cannot open database");
    }
    else {
        sqlite3_exec(db, "PRAGMA encoding = 'UTF-8';", NULL, NULL, NULL);
    }

    // sql ����
    char* sql = "SELECT id, b_name, b_dongnum, floor, sigun_gu, rent_type, deposit, fee, pyeong FROM BUILDINGS WHERE sigun_gu = ? AND rent_type = ? AND deposit BETWEEN ? AND ? AND fee BETWEEN ? AND ? AND pyeong BETWEEN ? AND ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); // SQL ���� �غ��Ͽ� stmt�� ����

    if (rc != SQLITE_OK) {
        return handleSQLiteError(db, rc, "Failed to prepare statement");
    }

    // ���ε� �Լ� ȣ��
    if (bindCharParameters(stmt, sigun_gu, parameterIndex++) != 0) { // ù ��° ���ε� ȣ��
        sqlite3_finalize(stmt); // SQLite �� ����
        sqlite3_close(db); // �����ͺ��̽� �ݱ�
        return 1; // ���α׷� ����
    }

    if (bindCharParameters(stmt, rent_type, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, minDeposit, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, maxDeposit, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, minFee, parameterIndex++) != 0) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    if (bindNumParameters(stmt, maxFee, parameterIndex++) != 0) {
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
        printf("                                         >>> ���ǿ� �����ϴ� �Ź��� �������� �ʽ��ϴ�. \n\n");
        return 0;
    }

    printf("-----------------------------------------------------------------------------------------------\n");
    printf(" %s    %15s        %5s    %3s    %5s      %5s    %5s     %5s \n",
        "��ȣ", "�ǹ���", "����ȣ", "��", "����", "Ÿ��", "����", "���");
    printf("-----------------------------------------------------------------------------------------------\n");


    // �������� �ѱ��� ����ϵ��� ��ȯ
    setlocale(LC_ALL, "ko_KR.UTF-8");

    // SQL �� ���� �� ��� ó��
    while (sqlite3_step(stmt) == SQLITE_ROW && result <= 10) { // SQL �� ���� �� ����� �ִ� ��� (�� ������ �ϳ� ������)
        int i;
        int num_cols = sqlite3_column_count(stmt); // ��� ������ �� ��

        for (i = 0; i < num_cols; i++) { // �� ���� ���� �ݺ�
            const unsigned char* col_value = sqlite3_column_text(stmt, i); // �� ��

            if (i == 0) {
                id[count] = atoi((const char*)col_value);
                printf("%3d ", count++);
                continue;
            }

            if (i == 1) {
                printf("%-30s ", col_value); //�ǹ�
                continue;
            }
            printf("%8s ", col_value);
        }
        printf("\n");
        result++;
        if (result == 10) {
            setlocale(LC_ALL, "C");
            do {
                printf("\n\n ����       [1] �˻� ��� ������               [2] �˻� ���� �� �� ���� Ȯ��     \n\n  �Է�:  ");
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

    // �۾��� ������ ������ �����Ϸ� ����
    setlocale(LC_ALL, "C");

    return --count;
}
