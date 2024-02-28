//search.c
#include "method.h"

int search() {
	int choice1, choice2, stop = 1, re;
	DET dInfo;
	char tmp[100];

	while (stop) {
		printf("\n------------------------------------- | 매 물 검 색 | ----------------------------------------\n\n");

		do
		{
			printf("               |1| 검색 |                             |2| 프로그램 종료 | \n    입력:  ");
			gets(tmp);
			choice1 = atoi(tmp);

		} while ((choice1 == 0 && tmp[0] != '0') || (choice1 != 1 && choice1 != 2));

		re = 1;
		
		switch (choice1)
		{
		case 1: dInfo = input();
			if (dInfo.count != 0) {
				while (re) {

					do
					{
						printf("\n\n ▶▶       [1] 상세 정보 확인                            [2] 뒤로가기     \n\n  입력:  ");
						gets(tmp);
						choice2 = atoi(tmp);

					} while ((choice2 == 0 && tmp[0] != '0') || (choice2 != 1 && choice2 != 2));

					switch (choice2)
					{
					case 1: searchDetail(dInfo);
						break;
					case 2: re = 0;
						break;
					}
				}
			}
			break;
		case 2: stop = 0;
			break;
		default:  printf("\n                                                    >>> 경고 : 1~2값만 입력해주세요. \n\n");
			break;
		}

	}

	printf("                                                            >>> 검색이 종료되었습니다. \n");


	return choice1;
}