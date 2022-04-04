/*
	한 판의 피자를 1조각 or 2조각씩 나누려고 한다. 피자가 4조각인 경우

- (1칸, 1칸, 1칸, 1칸)

- (1칸, 2칸, 1칸)

- (1칸, 1칸, 2칸)

- (2칸, 1칸, 1칸)

- (2칸, 2칸)

의 5가지 방법으로 피자를 나눌 수 있다. 한 판의 피자의 조각 수 N이 주어질 때, 1조각, 2조각씩 나누는 방법이 몇 가지인지 알아내 출력하는 프로그램을 완성하세요. 

예를 들어 4가 입력된다면, 5를 return 한다.
*/

#include<iostream>
using namespace std;

int Tot_combination(int);//총 경우의 수를 반환하는 함수
int combination(int, int);//nCr
int Factorial(int);

int main(void)
{
	int piz_piece;// 총 피자 조각 수
	cout << "총 피자 조각 수 :";
	cin >> piz_piece;
	cout << "최대 2조각씩 분배할 수 있는 경우의 수 : " << Tot_combination(piz_piece) << endl;
	return 0;
}

int Tot_combination(int tot_piece)
{
	int piz2pic_num = tot_piece / 2;//piz2pic_num는 피자 2개씩 나눈 몪
	int r=1;//nCr경우의 수를 사용하기 위함
	int numofway_sum = 1;

	if (tot_piece%2 == 0 )
	{
		for (int i = tot_piece - 1; i > piz2pic_num - 1; i--)
		{
			numofway_sum += combination(i, r);
			r++;
		}
	}
	else
	{
		for (int i = tot_piece - 1; i > piz2pic_num; i--)
		{
			numofway_sum += combination(i, r);
			r++;
		}
	}
	return numofway_sum;
}

int combination(int m,int n)
{
	if (n == 1)
		return m;
	else
	{
		return (Factorial(m) / (Factorial(n) * Factorial(m - n)));
	}
}

int Factorial(int k)// combination함수를 위한 세부 Factorial함수
{
	if (k == 0 || k == 1) return 1;
	else
		return (k * Factorial(k - 1));
}