//search.c
#include "method.h"

int search() {
	int choice1, choice2, stop = 1, re;
	DET dInfo;
	char tmp[100];

	while (stop) {
		printf("\n------------------------------------- | �� �� �� �� | ----------------------------------------\n\n");

		do
		{
			printf("               |1| �˻� |                             |2| ���α׷� ���� | \n    �Է�:  ");
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
						printf("\n\n ����       [1] �� ���� Ȯ��                            [2] �ڷΰ���     \n\n  �Է�:  ");
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
		default:  printf("\n                                                    >>> ��� : 1~2���� �Է����ּ���. \n\n");
			break;
		}

	}

	printf("                                                            >>> �˻��� ����Ǿ����ϴ�. \n");


	return choice1;
}