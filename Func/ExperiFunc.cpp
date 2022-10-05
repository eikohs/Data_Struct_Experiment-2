#include "Experiment2.h"

StaPtr Find_First_Bracket(char* src, int len)//找到至少一个右括号，并初始化栈，若没找到右括号则返回NULL值
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
int Find_Bracket(StaPtr s, char* src, int len)//跳过数字找到下一个右括号并返回对应的len值，没找到右括号则返回0
{
	while (len > 0 && !Is_Bracket(src[len - 1])) len--;
	if (Is_Bracket(src[len - 1]))
	{
		push(')', s);
		len--;
	}

	return len;
}
int Find_Operator(StaPtr s, char* src, int len)//跳过数字找到下一个运算符，没找到则返回0，同时在查找过程中若发现右括号则将其入栈
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
int Add_Bracket(StaPtr s, char* src,int * flag, int len)//栈顶为运算符时进行添加左括号操作，同时进行出栈操作
{
	while (len > 0 && !Is_Operator(src[len - 1]) && !Is_Bracket(src[len - 1]))	len--;
	flag[len]++;
	pop(s);
	pop(s);
	return len;
}
int Is_Operator(char c)//检测是否是运算符，是则返回1，否则返回0
{
	return(c == '*' || c == '/' || c == '+' || c == '-');
}
int Is_Bracket(char c)//检测是否为右括号，是则返回1，否则返回0
{
	return (c == ')');
}
