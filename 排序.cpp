#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

//qsort -- 库函数 -- 排序


//普通冒泡排序
void bubble_sort(int arr[10], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void* e1, const void* e2)
{	
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;
	//return (int)(*(float*)e1 - *(float*)e2);
}


void test()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]),cmp_int);

	//bubble_sort(arr, sz);

	for (int i = 0; i < sz; i++)
	{	
		printf("%d ", arr[i]);
	}
}

void test1()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	int sz = sizeof(f) / sizeof(f[1]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	
	for (int i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}

struct stu
{
	char name[20];
	int age;
};

int cmp_struct(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

void test2()
{
	struct stu s[3] = { {"张三",20},{"李四",30},{"王五",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}

//冒泡排序进阶
void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}

void Bubble_sort(void* base,int sz,int width,int (*cmp)(const void* e1,const void* e2))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}

void test3()
{
	struct stu s[3] = { {"张三",20},{"李四",30},{"王五",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	Bubble_sort(s, sz, sizeof(s[0]),cmp_stu_by_name);

	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}
int main()
{	

	//test();
	//test1();
	test3();

	system("pause");
	return 0;
}
