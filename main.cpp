/*
	3주차 이온과제
	- 입력된 6개 수의 합을 구하는 문제
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr_sum(int* ptr);

int main(void)
{
	int numarr[6] = { 0 };

	scanf("%d %d %d %d %d %d", &numarr[0], &numarr[1], &numarr[2], &numarr[3], &numarr[4], &numarr[5]);

	printf("\n%d\n", arr_sum(numarr));

	return 0;
}

int arr_sum(int* ptr)
{
	int sum_in_fun = 0;
	for (int i = 0; i < 6; i++)
	{
		sum_in_fun += ptr[i];
	}

	return sum_in_fun;
}