//input.c
#include "method.h"

DET input() {
	int replay;
	char sigun_gu[20];
	char rent_type[20];
	int place, rent, minPyeong, maxPyeong, minPrice, maxPrice, minDeposit, maxDeposit, minFee, maxFee;
	DET dInfo;
	char tmp[500]; // �ӽ÷� �Է¹��� ���ڿ�

out:
	do
	{
		printf("\n                                       �� �� �� �� �� ��                         \n\n");
		printf("         [1] ������       [2] ���빮��         [3] ��������          [4] ��걸    \n\n   �Է�:  ");

		gets(tmp);
		place = atoi(tmp);
	} while (place == 0 && tmp[0] != '0' || (place < 1 || place > 4));

	if (place == 1) {
		strcpy(sigun_gu, "Mapo-gu");
	}
	else if (place == 2) {
		strcpy(sigun_gu, "Seodaemun-gu");
	}
	else if (place == 3) {
		strcpy(sigun_gu, "Yeongdeungpo-gu");
	}
	else if (place == 4) {
		strcpy(sigun_gu, "Yongsan-gu");
	}


	//��ƮŸ�� �Է� �� ��ƮŸ�� ���ڷ� �Է� �� �ߴ��� ����
out1:
	do
	{
		printf("\n                                       �� �� Ʈ Ÿ �� ��                         \n\n");
		printf("         [1] �Ÿ�         [2] ����            [3] ����          [-1�� �ڷΰ���]    \n\n  �Է�:  ");


		gets(tmp);
		rent = atoi(tmp);
		if (rent == -1)
		{
			printf("\n-------------------------------------------------------------------------------------------------\n");
			goto out;
		}
	} while ((rent == 0 && tmp[0] != '0') || (rent < 0 || rent > 3));



	//��ƮŸ�Ժ� ���� ����� ������ ���� �� ���� ����
	switch (rent)
	{
	case 1:
		strcpy(rent_type, "Sale");
	out2:
		do
		{
			printf("\n                                       �� �� �� �� �� ��                         \n\n");
			printf("  0 ~ 2000000(����, �ִ� 200��) ������ �Ÿ� ������ �Է��ϼ���.     [-1�� �ڷΰ���]\n\n");
			printf("  �ּ� ���� �Է�:  ");
			gets(tmp);
			minPrice = atoi(tmp);
			if (minPrice == -1) 
			{
				goto out1;
			};
		} while ((minPrice == 0 && tmp[0] != '0') || minPrice < 0 || minPrice > 2000000);



	out3:
		do
		{
			printf("  �ִ� ���� �Է�:  ");
			gets(tmp);
			maxPrice = atoi(tmp);
			if (maxPrice == -1)
			{
				printf("\n-----------------------------------------------------------------------------------------------\n");
				goto out2;
			}

		} while ((maxPrice == 0 && tmp[0] != '0') || maxPrice < minPrice || maxPrice > 2000000);

		break;




	case 2:
		strcpy(rent_type, "Lease");


	out4:
		do
		{
			printf("\n                                       �� �� �� �� �� ��                         \n\n");
			printf("  0 ~ 1300000(����, �ִ� 130��) ������ ������ ������ �Է��ϼ���.   [-1�� �ڷΰ���]\n\n");
			printf("  �ּ� ���� �Է�:  ");

			gets(tmp);
			minDeposit = atoi(tmp);
			if (minDeposit == -1)
			{
				goto out1;
			}

		} while ((minDeposit == 0 && tmp[0] != '0') || minDeposit < 0 || minDeposit>1300000);

	out5:
		do
		{
			printf("  �ִ� ���� �Է�:  ");
			gets(tmp);
			maxDeposit = atoi(tmp);
			if (maxDeposit == -1)
			{
				printf("\n-----------------------------------------------------------------------------------------------\n");

				goto out4;
			}
				

		} while ((maxDeposit == 0 && tmp[0] != '0') || maxDeposit < minDeposit || maxDeposit > 1300000);
		break;

	case 3:
		strcpy(rent_type, "Monthly rent");
	out6:
		do
		{
			printf("\n                                       �� �� �� �� �� ��                         \n\n");
			printf("  0 ~ 500000(����, �ִ� 50��) ������ ������ ������ �Է��ϼ���.     [-1�� �ڷΰ���]\n\n");
			printf("  �ּ� ���� �Է�:  ");

			gets(tmp);
			minDeposit = atoi(tmp);
			if (minDeposit == -1)
			{
				goto out1;
			}
		} while ((minDeposit == 0 && tmp[0] != '0') || minDeposit < 0 || minDeposit > 2000000);


	out7:
		do
		{
			printf("  �ִ� ���� �Է�:  ");
			gets(tmp);
			maxDeposit = atoi(tmp);
			if (maxDeposit == -1)
			{
				printf("\n-----------------------------------------------------------------------------------------------\n");
				goto out6;

			}
		} while ((maxDeposit == 0 && tmp[0] != '0') || maxDeposit < minDeposit || maxDeposit > 1300000);

	out8:
		do
		{
			printf("\n\n  0 ~ 3500(����, �ִ� 3500��) ������ ���� ������ �Է��ϼ���.     [-1�� �ڷΰ���]\n\n");
			printf("  �ּ� ���� �Է�:  ");


			gets(tmp);
			minFee = atoi(tmp);
			if (minFee == -1)
				goto out7;
		} while ((minFee == 0 && tmp[0] != '0') || minFee < 0 || minFee > 3500);

	out9:
		do
		{
			printf("  �ִ� ���� �Է�:  ");
			gets(tmp);
			maxFee = atoi(tmp);
			if (maxFee == -1)
			{
				printf("\n-----------------------------------------------------------------------------------------------\n");
				goto out8;
			}
		} while ((maxFee == 0 && tmp[0] != '0') || maxFee < minFee || maxFee > 3500);

		break;
	}

	//��� �Է� �� ���� 
out10:
	do
	{
		printf("\n                                       �� �� �� �� �� ��                         \n\n");
		printf("  0 ~ 80(��) ������ ��� ����� �Է��ϼ���.                  [-1�� �ڷΰ���]\n\n");
		printf("  �ּ� ��� �Է�:  ");

		gets(tmp); //10, abc=0
		minPyeong = atoi(tmp);
		if (minPyeong == -1) {
			if (rent == 1) {
				goto out3;
			}
			else if (rent == 2) {
				goto out5;
			}
			else if (rent == 3) {
				goto out9;
			}
		}
	} while ((minPyeong == 0 && tmp[0] != '0') || minPyeong < 0 || minPyeong > 85); //tmp[0] =0 => ���� 0�� ���Դ�, tmp[0] != 0�� tmp�� ���ڿ��̴�

	do
	{
		printf("  �ִ� ��� �Է�:  ");
		gets(tmp);
		maxPyeong = atoi(tmp);
		if (maxPyeong == -1)
		{
			goto out10;
			printf("\n-----------------------------------------------------------------------------------------------\n");
		}
	} while ((maxPyeong == 0 && tmp[0] != '0') || maxPyeong < 0 || maxPyeong > 85);




	if (rent == 1) {
		printf("\n\n====================================================================================================\n");
		printf("\n                                       �� �� �� �� �� �� �� ��                         \n\n");
		printf("       %s   /     %s(�Ÿ�)   /  %d ~ %d����  /    %d ~ %d��  \n", 
			sigun_gu, rent_type, minPrice, maxPrice, minPyeong, maxPyeong);
		printf("\n\n====================================================================================================\n");

		do
		{
			printf("  �ش� �������� �˻��Ͻðڽ��ϱ�?\n\n");
			printf("           |0| �ٽ� ���� |                            |1| �˻� | \n  �Է�:  ");
			gets(tmp);
			replay = atoi(tmp);

		} while ((replay == 0 && tmp[0] != '0') || (replay != 1 && replay != 0));

		if (replay == 0) goto out;

		dInfo.count = selectSale(sigun_gu, rent_type, minPrice, maxPrice, minPyeong, maxPyeong);
	}
	else if (rent == 2) {
		printf("\n\n====================================================================================================\n");
		printf("\n                                       �� �� �� �� �� �� �� ��                         \n\n");
		printf("      %s     /    %s(����)   /   %d ~ %d����(������)  /  %d ~ %d��  \n",
			sigun_gu, rent_type, minDeposit, maxDeposit, minPyeong, maxPyeong);
		printf("\n\n====================================================================================================\n");


		do
		{
			printf("  �ش� �������� �˻��Ͻðڽ��ϱ�?\n\n");
			printf("           |0| �ٽ� ���� |                            |1| �˻� | \n  �Է�:  ");
			gets(tmp);
			replay = atoi(tmp);

		} while ((replay == 0 && tmp[0] != '0') || (replay != 1 && replay != 0));

		if (replay == 0) goto out;

		dInfo.count = selectLease(sigun_gu, rent_type, minDeposit, maxDeposit, minPyeong, maxPyeong);
	}
	else if (rent == 3) {
		printf("\n\n====================================================================================================\n");
		printf("\n                                       �� �� �� �� �� �� �� ��                         \n\n");
		printf("         %s   /   %s(����)  /  %d ~ %d����(������)   \n\n         %d ~ %d����(����)  /  %d ~ %d��  \n",
			sigun_gu, rent_type, minDeposit, maxDeposit, minFee, maxFee, minPyeong, maxPyeong);
		printf("\n\n====================================================================================================\n");


		do
		{
			printf("  �ش� �������� �˻��Ͻðڽ��ϱ�?\n\n");
			printf("           |0| �ٽ� ���� |                            |1| �˻� | \n  �Է�:  ");
			gets(tmp);
			replay = atoi(tmp);

		} while ((replay == 0 && tmp[0] != '0') || (replay != 1 && replay != 0));

		if (replay == 0) goto out;

		dInfo.count = selectMonthlyRent(sigun_gu, rent_type, minDeposit, maxDeposit, minFee, maxFee, minPyeong, maxPyeong);
	}

	dInfo.rentType = rent;

	return dInfo;
}