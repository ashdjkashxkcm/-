#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<errno.h>

//int main()
//{	
//	//动态内存的开辟    在内存中申请10个整型空间
//	//int* p =(int*)malloc(10 * sizeof(int));
//	//calloc会将开辟好的空间初始化为0，但效率比malloc低
//	int* p = (int*)calloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));
//	}
//	else
//	{	
//		//正常使用空间
//		for (int i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (int j = 0; j < 10; j++)
//		{
//			printf("%d", *(p + j));
//		}
//	}
//	//当动态内存不使用时，就应该归还给操作系统
//	free(p);
//	p = NULL;
//
//	system("pause");
//	return 0;
//}

//struct s
//{
//	int a;
//	int arr[0];//柔性数组   数组的大小是可以调整的
//};


//struct s1
//{
//	int a;
//	int* arr;
//};

int main()
{	
	//struct s* p = (struct s*)malloc((sizeof(struct s) + 5 * sizeof(int)));
	
	//struct s1* p1 = (struct s1*)malloc(sizeof(struct s1));//相比于柔性数组  该方法利用率更低

	//p1->arr = (int*)malloc(5 * sizeof(int));
	
	//打开文件text.txt
	//..表示上一路径
	//.表示当前路径
	//fopen("../text.txt","r");

	//相对路径写法
	//fopen("text.txt","r");

	//绝对路径写法
	//fopen("E:\c++ xiang mu\4_28\4_28\text,txt", "r");

	FILE* p = fopen("text.txt", "w");
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	fputc('h', p);
	printf("%c", fgetc(p));

	//关闭文件
	fclose(p);
	p = NULL;
	

	system("pause");
	return 0;
}

