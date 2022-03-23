/*
	E_on_project
	- 거품정렬
	- 중복된 입력값은 없다고 가정
	- 6개의 주어진 값을 배열로 받아 오름차순 정렬
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define size 6

void bubblesort(int *arr, int n);

int main(void)//6개의 값 입력받기
{
	int* arr_bubble;
	arr_bubble = (int*)malloc(sizeof(int) * size);//메모리의 동적할당
	
	scanf("%d %d %d %d %d %d", 
		&arr_bubble[0], &arr_bubble[1], &arr_bubble[2], &arr_bubble[3], &arr_bubble[4], &arr_bubble[5]);
	
	bubblesort(arr_bubble, size);
	
	free(arr_bubble);

	return 0;
}


void bubblesort(int *arrB, int n)//오름차순 정렬
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
