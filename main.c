/*
	E_on_project
	- ��ǰ����
	- �ߺ��� �Է°��� ���ٰ� ����
	- 6���� �־��� ���� �迭�� �޾� �������� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define size 6

void bubblesort(int *arr, int n);

int main(void)//6���� �� �Է¹ޱ�
{
	int* arr_bubble;
	arr_bubble = (int*)malloc(sizeof(int) * size);//�޸��� �����Ҵ�
	
	scanf("%d %d %d %d %d %d", 
		&arr_bubble[0], &arr_bubble[1], &arr_bubble[2], &arr_bubble[3], &arr_bubble[4], &arr_bubble[5]);
	
	bubblesort(arr_bubble, size);
	
	free(arr_bubble);

	return 0;
}


void bubblesort(int *arrB, int n)//�������� ����
{
	int jtemp = 0;
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arrB[j] > arrB[j + 1])
			{
				jtemp = arrB[j];
				arrB[j] = arrB[j + 1];
				arrB[j + 1] = jtemp;
			}
		}
	}

	printf("[ %d, %d, %d, %d, %d, %d ]\n", arrB[0], arrB[1], arrB[2], arrB[3], arrB[4], arrB[5]);
}
