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
		printf("С��\n");
	}
	else
	{
		printf("���\n");
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


	unsigned char i = 0;// i�ķ�ΧΪ0-255 ����Ϊ��ѭ��
	for ( i = 0; i <= 255; i++)
	{
		printf("hello world");
	}

	system("pause");
	return 0;
}
