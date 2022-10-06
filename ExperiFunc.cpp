#include "Experiment2.h"

StaPtr Find_First_Bracket(char* src, int len)//�ҵ�����һ�������ţ�����ʼ��ջ����û�ҵ��������򷵻�NULLֵ
{
	StaPtr RetPtr;
	while (len > 0 && !Is_Bracket(src[len - 1])) len--;
	if (Is_Bracket(src[len - 1]))
	{
		len--;
		RetPtr = Creat_Stack(len);
		push('#', RetPtr);
	}
	else
	{
		RetPtr = NULL;
	}

	return RetPtr;
}
int Find_Bracket(StaPtr s, char* src, int len)//���������ҵ���һ�������Ų����ض�Ӧ��lenֵ��û�ҵ��������򷵻�0
{
	while (len > 0 && !Is_Bracket(src[len - 1])) len--;
	if (Is_Bracket(src[len - 1]))
	{
		push(')', s);
		len--;
	}

	return len;
}
int Find_Operator(StaPtr s, char* src, int len)//���������ҵ���һ���������û�ҵ��򷵻�0��ͬʱ�ڲ��ҹ�����������������������ջ
{
	while (len > 0 && !Is_Operator(src[len - 1]))
	{
		if (Is_Bracket(src[len - 1]))
		{
			push(')', s);
		}
		len--;
	}
	if (Is_Operator(src[len - 1]))
	{
		push(src[len - 1], s);
		if (len > 1 && Is_Bracket(src[len - 2]))
		{
			push(')', s);
			len--;
		}
		len--;
	}

	return len;
}
int Add_Bracket(StaPtr s, char* src,int * flag, int len)//ջ��Ϊ�����ʱ������������Ų�����ͬʱ���г�ջ����
{
	while (len > 0 && !Is_Operator(src[len - 1]) && !Is_Bracket(src[len - 1]))	len--;
	flag[len]++;
	pop(s);
	pop(s);
	return len;
}
int Is_Operator(char c)//����Ƿ�������������򷵻�1�����򷵻�0
{
	return(c == '*' || c == '/' || c == '+' || c == '-');
}
int Is_Bracket(char c)//����Ƿ�Ϊ�����ţ����򷵻�1�����򷵻�0
{
	return (c == ')');
}
int Judge_Ret(StaPtr s, QueuePtr que)//����Ƿ�Ϊ�������У����򷵻�1�����򷵻�0
{
	while (!isEmpty(s) && !Que_Empty(que))
	{
		if (Top_Pop_Element(s) != Top_Pop_Que(que)) return 0;
	}

	return 1;
}