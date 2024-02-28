//input.c
#include "method.h"

DET input() {
	int replay;
	char sigun_gu[20];
	char rent_type[20];
	int place, rent, minPyeong, maxPyeong, minPrice, maxPrice, minDeposit, maxDeposit, minFee, maxFee;
	DET dInfo;
	char tmp[500]; // 임시로 입력받을 문자열

out:
	do
	{
		printf("\n                                       ▼ 지 역 선 택 ▼                         \n\n");
		printf("         [1] 마포구       [2] 서대문구         [3] 영등포구          [4] 용산구    \n\n   입력:  ");

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


	//렌트타입 입력 및 렌트타입 숫자로 입력 잘 했는지 검증
out1:
	do
	{
		printf("\n                                       ▼ 렌 트 타 입 ▼                         \n\n");
		printf("         [1] 매매         [2] 전세            [3] 월세          [-1로 뒤로가기]    \n\n  입력:  ");


		gets(tmp);
		rent = atoi(tmp);
		if (rent == -1)
		{
			printf("\n-------------------------------------------------------------------------------------------------\n");
			goto out;
		}
	} while ((rent == 0 && tmp[0] != '0') || (rent < 0 || rent > 3));



	//렌트타입별 숫자 제대로 들어갔는지 검증 및 예산 검증
	switch (rent)
	{
	case 1:
		strcpy(rent_type, "Sale");
	out2:
		do
		{
			printf("\n                                       ▼ 예 산 입 력 ▼                         \n\n");
			printf("  0 ~ 2000000(만원, 최대 200억) 사이의 매매 예산을 입력하세요.     [-1로 뒤로가기]\n\n");
			printf("  최소 예산 입력:  ");
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
			printf("  최대 예산 입력:  ");
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
			printf("\n                                       ▼ 예 산 입 력 ▼                         \n\n");
			printf("  0 ~ 1300000(만원, 최대 130억) 사이의 보증금 예산을 입력하세요.   [-1로 뒤로가기]\n\n");
			printf("  최소 예산 입력:  ");

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
			printf("  최대 예산 입력:  ");
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
			printf("\n                                       ▼ 예 산 입 력 ▼                         \n\n");
			printf("  0 ~ 500000(만원, 최대 50억) 사이의 보증금 예산을 입력하세요.     [-1로 뒤로가기]\n\n");
			printf("  최소 예산 입력:  ");

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
			printf("  최대 예산 입력:  ");
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
			printf("\n\n  0 ~ 3500(만원, 최대 3500만) 사이의 월세 예산을 입력하세요.     [-1로 뒤로가기]\n\n");
			printf("  최소 예산 입력:  ");


			gets(tmp);
			minFee = atoi(tmp);
			if (minFee == -1)
				goto out7;
		} while ((minFee == 0 && tmp[0] != '0') || minFee < 0 || minFee > 3500);

	out9:
		do
		{
			printf("  최대 예산 입력:  ");
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

	//평수 입력 및 검증 
out10:
	do
	{
		printf("\n                                       ▼ 평 수 입 력 ▼                         \n\n");
		printf("  0 ~ 80(평) 사이의 희망 평수를 입력하세요.                  [-1로 뒤로가기]\n\n");
		printf("  최소 평수 입력:  ");

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
	} while ((minPyeong == 0 && tmp[0] != '0') || minPyeong < 0 || minPyeong > 85); //tmp[0] =0 => 실제 0이 들어왔다, tmp[0] != 0은 tmp가 문자열이다

	do
	{
		printf("  최대 평수 입력:  ");
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
		printf("\n                                       ▼ 최 종 입 력 내 역 ▼                         \n\n");
		printf("       %s   /     %s(매매)   /  %d ~ %d만원  /    %d ~ %d평  \n", 
			sigun_gu, rent_type, minPrice, maxPrice, minPyeong, maxPyeong);
		printf("\n\n====================================================================================================\n");

		do
		{
			printf("  해당 조건으로 검색하시겠습니까?\n\n");
			printf("           |0| 다시 선택 |                            |1| 검색 | \n  입력:  ");
			gets(tmp);
			replay = atoi(tmp);

		} while ((replay == 0 && tmp[0] != '0') || (replay != 1 && replay != 0));

		if (replay == 0) goto out;

		dInfo.count = selectSale(sigun_gu, rent_type, minPrice, maxPrice, minPyeong, maxPyeong);
	}
	else if (rent == 2) {
		printf("\n\n====================================================================================================\n");
		printf("\n                                       ▼ 최 종 입 력 내 역 ▼                         \n\n");
		printf("      %s     /    %s(전세)   /   %d ~ %d만원(보증금)  /  %d ~ %d평  \n",
			sigun_gu, rent_type, minDeposit, maxDeposit, minPyeong, maxPyeong);
		printf("\n\n====================================================================================================\n");


		do
		{
			printf("  해당 조건으로 검색하시겠습니까?\n\n");
			printf("           |0| 다시 선택 |                            |1| 검색 | \n  입력:  ");
			gets(tmp);
			replay = atoi(tmp);

		} while ((replay == 0 && tmp[0] != '0') || (replay != 1 && replay != 0));

		if (replay == 0) goto out;

		dInfo.count = selectLease(sigun_gu, rent_type, minDeposit, maxDeposit, minPyeong, maxPyeong);
	}
	else if (rent == 3) {
		printf("\n\n====================================================================================================\n");
		printf("\n                                       ▼ 최 종 입 력 내 역 ▼                         \n\n");
		printf("         %s   /   %s(월세)  /  %d ~ %d만원(보증금)   \n\n         %d ~ %d만원(월세)  /  %d ~ %d평  \n",
			sigun_gu, rent_type, minDeposit, maxDeposit, minFee, maxFee, minPyeong, maxPyeong);
		printf("\n\n====================================================================================================\n");


		do
		{
			printf("  해당 조건으로 검색하시겠습니까?\n\n");
			printf("           |0| 다시 선택 |                            |1| 검색 | \n  입력:  ");
			gets(tmp);
			replay = atoi(tmp);

		} while ((replay == 0 && tmp[0] != '0') || (replay != 1 && replay != 0));

		if (replay == 0) goto out;

		dInfo.count = selectMonthlyRent(sigun_gu, rent_type, minDeposit, maxDeposit, minFee, maxFee, minPyeong, maxPyeong);
	}

	dInfo.rentType = rent;

	return dInfo;
}