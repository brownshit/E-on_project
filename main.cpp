/*
	�� ���� ���ڸ� 1���� or 2������ �������� �Ѵ�. ���ڰ� 4������ ���

- (1ĭ, 1ĭ, 1ĭ, 1ĭ)

- (1ĭ, 2ĭ, 1ĭ)

- (1ĭ, 1ĭ, 2ĭ)

- (2ĭ, 1ĭ, 1ĭ)

- (2ĭ, 2ĭ)

�� 5���� ������� ���ڸ� ���� �� �ִ�. �� ���� ������ ���� �� N�� �־��� ��, 1����, 2������ ������ ����� �� �������� �˾Ƴ� ����ϴ� ���α׷��� �ϼ��ϼ���. 

���� ��� 4�� �Էµȴٸ�, 5�� return �Ѵ�.
*/

#include<iostream>
using namespace std;

int Tot_combination(int);//�� ����� ���� ��ȯ�ϴ� �Լ�
int combination(int, int);//nCr
int Factorial(int);

int main(void)
{
	int piz_piece;// �� ���� ���� ��
	cout << "�� ���� ���� �� :";
	cin >> piz_piece;
	cout << "�ִ� 2������ �й��� �� �ִ� ����� �� : " << Tot_combination(piz_piece) << endl;
	return 0;
}

int Tot_combination(int tot_piece)
{
	int piz2pic_num = tot_piece / 2;//piz2pic_num�� ���� 2���� ���� ��
	int r=1;//nCr����� ���� ����ϱ� ����
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

int Factorial(int k)// combination�Լ��� ���� ���� Factorial�Լ�
{
	if (k == 0 || k == 1) return 1;
	else
		return (k * Factorial(k - 1));
}