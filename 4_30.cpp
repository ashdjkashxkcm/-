#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>

int my_strlen(const char* str)
{	
	int count = 0;
	assert(str != NULL);
	while (*str)//while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

char* my_strcpy(char* dest,const char* src)
{
	assert(dest != NULL);
	assert(dest != NULL);
	char* ret = dest;
	//拷贝src中的字符串到dest，包含'\0'
	while (*dest++ = *src++);
	//返回目的空间的地址
	return ret;
}

char* my_strcat(char* dest,const char* src)
{	
	char* ret = dest;
	assert(dest && src);
	//找到'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	
	//追加
	while (*dest++ = *src++);
	return ret;
}

//字符串比较
int my_strcmp(const char* str1, const char* str2)
{	
	assert(str1 && str2);
	//字符串比较
	while (*str1 == *str2)
	{	
		//相等
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	//大于
	if (*str1 > *str2)
	{
		return 1;
	}
	else  //小于 
	{
		return -1;
	}

	// return (*str1 - *str2);    //大于返回正数   小于返回负数
}

//模拟实现strncpy
char* my_strncpy(char* str1, const char* str2,size_t sz)
{
	assert(str1 && str2);
	char* ret = str1;
	while (sz &&(*str1++ = *str2++))
	{
		sz--;
	}
	if (sz)
	{
		while (--sz)
		{
			*str1++ = '\0';
		}
	}
	return ret;
}
//char* my_strncpy(char* str1, const char* str2, size_t sz)
//{
//	assert(str1 && str2);
//	char* ret = str1;
//	while (sz--)
//	{
//		*str1++ = *str2++;
//	}
//
//	return ret;
//}

//模拟实现strncat
char* my_strncat(char* str1, char* str2, size_t sz)
{
	assert(str1 && str2);
	char* ret = str1;
	while (*str1++); //这里多加了一次
	str1--;  //所以这里需要减一次

	while (sz--)
		if (!(*str1++ = *str2++))
			return ret;
	*str1 = '\0';
	return ret;

	//while (sz && (*str1++ = *str2++))
	//{
	//	sz--;
	//}
	//if (sz)
	//	while (--sz)
	//		*str1 = '\0';
	return ret;
}

int main()
{	
	//int arr[10] = { 1,2,3,4 };
	//int* p = arr;

	////等价写法
	//*(p + 2) == p[2] == *(arr + 2) == arr[2];

	//求字符串长度
	//char arr[] = "abcdef";
	//int len = my_strlen(arr);
	//printf("%d\n", len);

	//		// 3      -       6    = -3    使用strlen  -3会被当作无符号数处理  所以最终打印hehe
	//if (strlen("abc") - strlen("abcdef") > 0)
	//{
	//	printf("hehe\n");
	//}
	//else {
	//	printf("haha\n");
	//}

	//char arr[30] = "hello";
	//char arr1[] = "world";
	//my_strcat(arr, arr1);
	//printf("%s\n", arr);

	char arr1[10] = "abcefh";
	char arr2[] = "he";
	my_strncpy(arr1, arr2, 4);
	
	printf("%s", arr1);

	system("pause");
	return 0;
}
