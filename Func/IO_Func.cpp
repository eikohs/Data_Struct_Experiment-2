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
int Get_Chars(StaPtr s, QueuePtr que)//从标准输入中读取以#结尾的字符串
{
	char c;
	while ((c = getchar()) == '\n')continue;
	if (c == '#') return 0;
	do
	{
		push(c, s);
		push_que(c, que);
	} while ((c = getchar()) != '#');

	return 1;
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