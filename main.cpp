/*
	3���� �̿°���
	- �Էµ� 6�� ���� ���� ���ϴ� ����
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

	printf("\n�հ�� ��...\n\n");

	return tot_num;
}
