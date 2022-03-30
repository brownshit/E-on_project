/*
	E-on_5주차 과제_201912512 원종찬
	- 수를 찾아라​
*/

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

/*
- array의 길이는 1 이상 100 이하입니다.

- array의 각 원소는 1 이상 100 이하입니다.

- commands의 길이는 1 이상 50 이하입니다.

- commands의 각 원소는 길이가 3입니다.
*/

//i,j,k를 멤버로 갖는 객체를 선언하였다.
class com {
public:
	int i, j, k;
};


//함수는 연산을 위한 solution함수와 정렬을 위한 Sort함수를 선언해줬다. 
int* solution(int** comm, int ijklen, int arrlen, int* return_arr);
int* Sort(int* arr, int n);



//배열의 요소와 i,j,k를 입력 받고, command라는 새로운 배열에 모든것을 집어넣어 한번에 solution함수로 전달한다
int main(void)
{
	int arr_len;
	int ijk_len;

	while (1)//array길이의 조건에 맞는 경우에만 whlie무한 반복문을 탈출할 수 있다
	{
		cout << "배열의 길이 입력 : ";
		cin >> arr_len;
		if (arr_len < 1 || arr_len>100)
		{
			cout << "배열의 길이 재입력!(배열의 길이는 1부터 100사이)" << endl;
		}
		else
		{
			break;
		}
	}

	int* arr = new int[arr_len];																//new arr의 동적할당

	cout << "배열의" << arr_len << "개의 요소 입력" << endl;
	for (int i = 0; i < arr_len; i++)
	{
		int arr_ele;//배열의 원소.
		cin >> arr_ele;
		if (arr_ele < 1 || arr_ele>100)//배열의 원소의 길이의 조건
		{
			cout << "배열의 원소는 1~100사이의 값만 입력해야 합니다" << endl;
			break;
		}
		else
		{
			arr[i] = arr_ele;
		}

	}
		
	while (1)//command길이의 조건에 맞는 경우에만 whlie무한 반복문을 탈출할 수 있다
	{
		cout << "command배열의 길이 입력(i,j,k쌍의 개수) : ";
		cin >> ijk_len;
		if (ijk_len < 1 || ijk_len>50)
		{
			cout << "command배열의 길이 재입력 필요" << endl;
		}
		else 
		{
			break;
		}
	}

	int** command = new int* [ijk_len];														//new command의 동적할당
	for (int x = 0; x < ijk_len; x++)									
		command[x] = new int[arr_len + 3];

	com* ijkarr = new com[ijk_len];

	cout << "ijk인수" << endl;
	

	/*
		command의 1차원부분의 [0],[1],[2]에는 각각 i,j,k를 넣어주고, 
		그 이후의 공간 ([3]이후의 공간) 에 배열 arr을 넣어주어, 
		정보를 최소화 시킨 command배열을 solution함수로 전달이 가능하다.
	*/
	for (int n = 0; n < ijk_len; n++)
	{
		cout << "[";
		cin >> ijkarr[n].i;
		command[n][0] = ijkarr[n].i;
		cin >> ijkarr[n].j;
		command[n][1] = ijkarr[n].j;
		cin >> ijkarr[n].k;
		command[n][2] = ijkarr[n].k;
		cout << "]";

		for (int m = 3; m < arr_len + 3; m++)
		{
			command[n][m] = arr[m - 3];
		}
	}
	
	int* return_arr = new int[ijk_len];										//return_arr의 동적할당
	
	solution(command, ijk_len, arr_len + 3, return_arr);
	//이때, command만이 인수로서 넘어가야만 한다.
	cout << "연산의 return 값 : " << "["<< return_arr[0];
	for (int v = 1; v < ijk_len; v++)
	{
		cout << "," << return_arr[v];
	}
	cout<< "]" << endl;

	// delete연산자를 통해 위에서 동적 할당된 메모리들을 해제시켜준다.
	delete[] return_arr;

	for (int x = 0; x < ijk_len; x++)
		delete[] command[x];
	delete [] command;

	delete [] arr;

	return 0;
}

int* solution(int **command, int ijksort_len, int ijk_p_arr_len, int* return_arr)
{
	//commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성
	
	for (int n = 0; n < ijksort_len; n++)
	{
		int i = command[n][0];
		int j = command[n][1]; 
		int k = command[n][2];
		int *new_arr = new int[j - i]; //각각의 ijk 원소의 경우에 대해 
		for (int m = i; m < j; m++)
		{
			new_arr[m - i] = command[n][m + 2];
		}
		new_arr = Sort(new_arr, j-i);

		return_arr[n] = new_arr[k-2];

		delete[] new_arr;
	}

	return return_arr;
}

int* Sort(int *arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int itemp = arr[i];
				arr[i] = arr[j];
				arr[j] = itemp;
			}
		}
	}

	return arr;
}