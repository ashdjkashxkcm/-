#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
//int main()
//{	
//	//ָ������
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 4,5,6,7 };
//	int arr3[] = { 7,8,9,10 };
//
//	int* parr[] = { arr1 , arr2,arr3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//
//	//����ָ��
//	char* arr[5];
//	char* (*p)[5] = &arr;
//
//
//	system("pause");
//	return 0;
//}

//void printf1(int arr[3][5],int x,int y)
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void printf2(int(*p)[5], int x, int y)
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	
//	printf1(arr, 3, 5);
//	printf2(arr, 3, 5);
//
//	system("pause");
//	return 0;
//}

//������ַ
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{	
//
//	//&������   ��  ������ ���Ǻ����ĵ�ַ
//	//printf("%p\n", Add);
//	//printf("%p\n", &Add);
//
//	int (*p)(int, int) = &Add;
//	int (*parr[4])(int, int) = {Add,Sub,Mul,Div};//����ָ�������
//	//printf("%d ", (*p)(2, 3));
//	//printf("%d ", p(2, 3));
//	
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d \n", (*parr[i])(2, 3));
//	}
//
//	system("pause");
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src);
//
//int main()
//{
//	char* (*pf)(char*, const char*) = &my_strcpy;
//	char* (*pfArr[4])(char*, const char*) = {my_strcpy,my_strcpy,my_strcpy,my_strcpy};
//
//
//
//	system("pause");
//	return 0;
//}

//������

//�˵�
void Menu()
{
	printf("**********************\n");
	printf("**** 1.Add   2.Sub ***\n");
	printf("**** 3.Mul   4.Div ***\n");
	printf("****    0.exit     ***\n");
	printf("**********************\n");
}
//�ӷ�
int Add(int x, int y)
{
	return x + y;
}
//����
int Sub(int x, int y)
{
	return x - y;
}
//�˷�
int Mul(int x, int y)
{
	return x * y;
}
//����	 
int Div(int x, int y)
{
	return x / y;
}

//int main()
//{	
//	int input = 0;
//	int x = 0,y =0;
//
//	do
//	{	
//		Menu();
//		printf("����������:\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("�������������֣�\n");
//			scanf("%d%d", &x, &y);
//			printf("%d \n",Add(x, y));
//			break;
//		case 2:
//			printf("�������������֣�\n");
//			scanf("%d%d", &x, &y);
//			printf("%d \n", Sub(x, y));
//			break;
//		case 3:
//			printf("�������������֣�\n");
//			scanf("%d%d", &x, &y);
//			printf("%d \n", Mul(x, y));
//			break;
//		case 4:
//			printf("�������������֣�\n");
//			scanf("%d%d", &x, &y);
//			printf("%d \n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳�\n");
//		default:
//			printf("�������");
//			break;
//		}
//		system("cls");
//	} while (input);
//
//	system("pause");
//	return 0;
//}

//ʹ�ú���ָ���Ż�
int main()
{
	int input = 0;
	int x = 0, y = 0;

	//pfarr ��һ������ָ������  ----  ת�Ʊ�
	int (*pfarr[5])(int, int) = { 0,Add,Sub,Mul,Div};

	//ָ����ָ�������ָ��
	int (*(*ppfArr)[5])(int, int) = &pfarr; 

	do
	{
		Menu();
		printf("����������:\n");
		scanf("%d", &input);
		
		if (input >= 1 && input <= 4)
		{
			printf("����������������:\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", pfarr[input](x,y));
		}
		else if (input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("�������\n");
		}
		system("pause");
		system("cls");
	} while (input);

	return 0;
}

//�Ż��ڶ���

//void Calc(int(*pf)(int, int))
//{	
//	int x = 0, y = 0;
//	printf("�������������֣�\n");
//	scanf("%d%d", &x, &y);
//	printf("%d \n", pf(x, y));
//}
//int main()
//{	
//	int input = 0;
//
//	do
//	{	
//		Menu();
//		printf("����������:\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("�˳�\n");
//		default:
//			printf("�������");
//			break;
//		}
//		system("pause");
//		system("cls");
//	} while (input);
//
//	return 0;
//}