#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<errno.h>

//int main()
//{	
//	//��̬�ڴ�Ŀ���    ���ڴ�������10�����Ϳռ�
//	//int* p =(int*)malloc(10 * sizeof(int));
//	//calloc�Ὣ���ٺõĿռ��ʼ��Ϊ0����Ч�ʱ�malloc��
//	int* p = (int*)calloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		printf("%s", strerror(errno));
//	}
//	else
//	{	
//		//����ʹ�ÿռ�
//		for (int i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (int j = 0; j < 10; j++)
//		{
//			printf("%d", *(p + j));
//		}
//	}
//	//����̬�ڴ治ʹ��ʱ����Ӧ�ù黹������ϵͳ
//	free(p);
//	p = NULL;
//
//	system("pause");
//	return 0;
//}

//struct s
//{
//	int a;
//	int arr[0];//��������   ����Ĵ�С�ǿ��Ե�����
//};


//struct s1
//{
//	int a;
//	int* arr;
//};

int main()
{	
	//struct s* p = (struct s*)malloc((sizeof(struct s) + 5 * sizeof(int)));
	
	//struct s1* p1 = (struct s1*)malloc(sizeof(struct s1));//�������������  �÷��������ʸ���

	//p1->arr = (int*)malloc(5 * sizeof(int));
	
	//���ļ�text.txt
	//..��ʾ��һ·��
	//.��ʾ��ǰ·��
	//fopen("../text.txt","r");

	//���·��д��
	//fopen("text.txt","r");

	//����·��д��
	//fopen("E:\c++ xiang mu\4_28\4_28\text,txt", "r");

	FILE* p = fopen("text.txt", "w");
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	fputc('h', p);
	printf("%c", fgetc(p));

	//�ر��ļ�
	fclose(p);
	p = NULL;
	

	system("pause");
	return 0;
}

