#include "Experiment2.h"

char* Get_Line(void)//�ӱ�׼�������ȡһ���������MAXCAP���ַ�������ָ��
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
void PRINT_SENTENCE(char* src, int* flag)//��ӡ��󲹳����ź�ı��ʽ
{
	for (int i = 0; i < strlen(src); i++)
	{
		for (int j = 0; j < flag[i]; j++) putchar('(');
		putchar(src[i]);
	}
	putchar('\n');
}
char* Get_Sting(void)//�ӱ�׼�������ȡһ����#��β���ַ���
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