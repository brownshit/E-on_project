/*
	3���� �̿°���
	- �Էµ� 6�� ���� ���� ���ϴ� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr_sum(int *ptr);

int main(void)
{
	int numarr[6] = { 0 };
	
	for (int i = 0; i < 6; i++)
		scanf("%d",&numarr[i]);
	
	printf("\n%d\n", arr_sum(numarr));

	return 0;
}

int arr_sum(int *ptr)
{
	int sum_in_fun = 0;
	for (int i = 0; i < 6; i++)
	{
		sum_in_fun += ptr[i];
	}

	return sum_in_fun;
}