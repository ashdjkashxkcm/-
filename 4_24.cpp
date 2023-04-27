#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

int check_sys()
{
	int a = 1;
	char* p = (char*)&a;
	return *p; 
}


int main()
{	

	/*int ret = check_sys();
	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}*/

	/*char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d b=%d c=%d\n", a, b, c);

	char d = -128;
	printf("%u", d);*/

	/*char a[1000];
	int i = 0;
	for (i; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf(" %d\n", strlen(a));*/


	//unsigned char i = 0;// i的范围为0-255 下面为死循环
	//for ( i = 0; i <= 255; i++)
	//{
	//	printf("hello world");
	//}

	float f = 5.5;
	//5.5
	//101.1
	// (-1)*0 *1.011*2^2;
	// -1 * S * M *2^ E
	//S = 0
	//M = 1.011
	//E = 2;
	//存储方式  S  E+127  M 
	//          0  129    011
	//0 10000001 01100000000000000000000

	system("pause");
	return 0;
}
