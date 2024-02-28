// method.h

// ���� ���̺귯��
#pragma comment(lib, "sqlite3.lib")
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

#ifndef _METHOD_H_
#define _METHOD_H_

// detail���� ������ ����ü (�˻� ��� ������ � rentType�� ���� �˻� ������� ����)
typedef struct DETAIL {
	int count;
	int rentType;
} DET;

// �˻� ����� id�� ������ �迭
int id[3000];

// �˻� �������� �� �Լ�
int search();

// ���� �Է¹��� �Լ�
DET input();

//renttype�� ���� ������ ã���� �Լ�
int selectSale(char sigun_gu[20], char rent_type[20], int minPrice, int maxPrice, int minPyeong, int maxPyeong);
int selectLease(char sigun_gu[20], char rent_type[20], int minDepoist, int maxDeposit, int minPyeong, int maxPyeong);
int selectMonthlyRent(char sigun_gu[20], char rent_type[20], int minDepoist, int maxDeposit, int minFee, int maxFee, int minPyeong, int maxPyeong);

// �������� �Ű������� bind���� �Լ�
int bindCharParameters(sqlite3_stmt* stmt, char* name, int parameterIndex);
int bindNumParameters(sqlite3_stmt* stmt, int num, int parameterIndex);

// SQLite���� �߻��� ������ ó���ϴ� �Լ�
int handleSQLiteError(sqlite3* db, int rc, const char* message); 

// �� ������ ����� �Լ�
int searchDetail(DET dInfo);
int selectDetail(int idx, int count, int rentType);

#endif 
