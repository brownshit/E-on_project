/*
	3주차 이온과제
	- 입력된 6개 수의 합을 구하는 문제
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int num_sum();

int main(void)
{
	printf("sum_total_output : %d\n", num_sum());
	return 0;
}

int num_sum()
{
	int arr_num[6]={0};
	int tot_num;
	tot_num = 0;

	for (int i = 0; i < 6; i++)
	{
		printf("num %d input : ", i);
		scanf("%d", &arr_num[i]);
		tot_num += arr_num[i];
	}

	printf("\n합계산 끝...\n\n");

	return tot_num;
}
