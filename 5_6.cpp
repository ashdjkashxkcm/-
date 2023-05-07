#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//int main()
//{	
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%c", strerror(errno));
//		return 0;
//	}
//	
//	//文件
//	fputs("hello\n", pf);
//	fputs("world", pf);
//
//	fclose(pf);
//	pf = NULL;
//
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//从键盘上读取一行文本信息
//	char arr[1024] = { 0 };
//
//	fgets(arr, 1024, stdin);
//	fputs(arr, stdin);
//
//	system("pause");
//	return 0;

//}
struct s
{
	int n;
	float f;
	char arr[10];

};

int main()
{	
	//struct s s1 = { 100,3.14f,"hello" };
	struct s s2 = { 0 };
	//FILE* pf = fopen("text.txt", "w");
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}

	//格式化的输出数据
	//fprintf(pf,"%d %f %s", s1.n, s1.f, s1.arr);
	//格式化的输入数据
	fscanf(pf, "%d %f %s", &(s2.n), &(s2.f), s2.arr);

	printf("%d %f %s\n", s2.n, s2.f, s2.arr);

	fclose(pf);
	pf = NULL;
	system("pause");
	return 0;
}