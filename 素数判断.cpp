#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{	
	//判度i是否为素数
	//1.试数法

	//for (int i = 100; i < 200; i++)
	//{
	//	int j = 0;
	//	for (j = 2; j < i; j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	if (j == i)
	//	{
	//		printf("%d", i);
	//	}

	//}

	//for (int i = 100; i < 200; i++)
	//{
	//	int j = 0;
	//	for (j = 2; j <= sqrt(i); j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	if (j > sqrt(i))
	//	{
	//		printf("%d   ", i);
	//	}
	//}

	for (int i = 101; i < 200; i+=2 )
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d   ", i);
		}

	}


	system("pause");
	return 0;
}
