#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{	
	//strtok
	char arr[] = "zwp@bitedu.tech";
	const char* p = "@.";

	char buf[1024] = { 0 };
	strcpy(buf, arr);

	//char* ret = strtok(buf, p);
	//printf("%s\n", ret);
	//
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);

	//ret = strtok(NULL, p);
	//printf("%s\n", ret);

	for (char* ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}

	system("pause");
	return 0;
}
