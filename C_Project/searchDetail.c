//searchDetail.c
#include "method.h"

int searchDetail(DET dInfo) {

	int choice; // ���� ��
	char tmp[100];

	do
	{
		printf("\n����  �Ź� ��ȣ�� �Է����ּ���: 1 ~ %d \n\n  �Է�: ", dInfo.count);
		gets(tmp);
		choice = atoi(tmp);

	} while ((choice == 0 && tmp[0] != '0') || (choice < 1 || choice > dInfo.count));

	// �󼼰˻� �Լ� ȣ��
	selectDetail(choice, dInfo.count, dInfo.rentType);


	return 0;
}