// method.h

// 공통 라이브러리
#pragma comment(lib, "sqlite3.lib")
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

#ifndef _METHOD_H_
#define _METHOD_H_

// detail값을 저장할 구조체 (검색 결과 개수와 어떤 rentType에 대한 검색 결과인지 저장)
typedef struct DETAIL {
	int count;
	int rentType;
} DET;

// 검색 결과의 id를 저장할 배열
int id[3000];

// 검색 로직으로 들어갈 함수
int search();

// 내용 입력받을 함수
DET input();

//renttype에 따라 데이터 찾아줄 함수
int selectSale(char sigun_gu[20], char rent_type[20], int minPrice, int maxPrice, int minPyeong, int maxPyeong);
int selectLease(char sigun_gu[20], char rent_type[20], int minDepoist, int maxDeposit, int minPyeong, int maxPyeong);
int selectMonthlyRent(char sigun_gu[20], char rent_type[20], int minDepoist, int maxDeposit, int minFee, int maxFee, int minPyeong, int maxPyeong);

// 쿼리문에 매개변수를 bind해줄 함수
int bindCharParameters(sqlite3_stmt* stmt, char* name, int parameterIndex);
int bindNumParameters(sqlite3_stmt* stmt, int num, int parameterIndex);

// SQLite에서 발생한 오류를 처리하는 함수
int handleSQLiteError(sqlite3* db, int rc, const char* message); 

// 상세 정보를 출력할 함수
int searchDetail(DET dInfo);
int selectDetail(int idx, int count, int rentType);

#endif 
