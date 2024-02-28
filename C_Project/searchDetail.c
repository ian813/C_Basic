//searchDetail.c
#include "method.h"

int searchDetail(DET dInfo) {

	int choice; // 선택 값
	char tmp[100];

	do
	{
		printf("\n▶▶  매물 번호를 입력해주세요: 1 ~ %d \n\n  입력: ", dInfo.count);
		gets(tmp);
		choice = atoi(tmp);

	} while ((choice == 0 && tmp[0] != '0') || (choice < 1 || choice > dInfo.count));

	// 상세검색 함수 호출
	selectDetail(choice, dInfo.count, dInfo.rentType);


	return 0;
}