#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//�ж�һ�����ǲ�������
int is_Prime(int n)
{
	for (int j = 2; j < i; j++)
	{
		if (i % j == 0)
		{	
			return 0; //������������0
		}

	}		
	return 1;//����������1
}

//�ж�����
int is_leap_Year(int n)
{
	if (n % 4 == 0 && n % 100 != 0)
	{
		return 1; //�����귵��1
	}
	else
	{
		return 0;//���Ƿ���0
	}
}

//���ֲ���
int binary_search(int arr[], int k)
{
	int right = sizeof(arr) / sizeof(arr[0])-1;
	int left = 0;
	int mide = right / 2;
	while (left <= right)
	{
		if (arr[mide] > k)
		{
			right = mide - 1;
		}
		if (arr[mide] < k)
		{
			left = mide + 1;
		}
		else 
		{
			return 1;
		}
	}
	if (left > right)
	{
		return 0;
	}
}

int main()
{	

	system("pause");
	return 0;
}
