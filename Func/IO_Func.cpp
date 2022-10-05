#include "Experiment2.h"

char* Get_Line(void)//从标准输入里读取一行最大容量MAXCAP的字符并返回指针
{
	char TmpStr[MAXCAP], c;
	int Len;
	while ((c = getchar()) == '\n') continue;
	for (Len = 0; c != '\n'; Len++)
	{
		TmpStr[Len] = c;
		c = getchar();
	}
	TmpStr[Len++] = '\0';
	char* RetPtr = (char*)malloc(sizeof(char) * Len);
	if (RetPtr == NULL) exit(1);
	strncpy(RetPtr, TmpStr, Len);

	return RetPtr;
}
void PRINT_SENTENCE(char* src, int* flag)//打印最后补充括号后的表达式
{
	for (int i = 0; i < strlen(src); i++)
	{
		for (int j = 0; j < flag[i]; j++) putchar('(');
		putchar(src[i]);
	}
	putchar('\n');
}
char* Get_Sting(void)//从标准输入里读取一段以#结尾的字符串
{
	char TmpStr[MAXCAP], c;
	int Len;
	while ((c = getchar()) == '\n') continue;
	for (Len = 0; c != '#'; Len++)
	{
		TmpStr[Len] = c;
		c = getchar();
	}
	TmpStr[Len++] = '\0';
	char* RetPtr = (char*)malloc(sizeof(char) * Len);
	if (RetPtr == NULL) exit(1);
	strncpy(RetPtr, TmpStr, Len);

	return RetPtr;
}
