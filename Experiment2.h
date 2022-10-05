#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST 0//1代表进入函数测试模式，0则反之
#define DEBUG 1//1代表调试模式，0则反之
#define WHETHER_PRINT 1//1代表通过打印调试，0则反之
//提交时上述三者应同时置零
#define PROGRAM_MODE 1//1代表题目一，2代表题目二，只能是二者之一
#define MAXCAP 100//代表栈的最大容量
#define EmptyTop -1//代表空栈时top的值

typedef char element;

typedef struct STACK {
    element* Array;
    int top;//代表栈顶元素
    int capacity;//栈的容量
}Stack, * StaPtr;

StaPtr Find_First_Bracket(char* src, int len);//找到至少一个右括号，并初始化栈
int Find_Bracket(StaPtr s, char* src, int len);//跳过数字找到下一个右括号
int Find_Operator(StaPtr s, char* src, int len);//跳过数字找到下一个运算符
int Add_Bracket(StaPtr s, char* src, int* flag, int len);//栈顶为运算符时进行添加左括号操作
int Is_Operator(char c);//检测是否是运算符，是则返回1，否则返回0
int Is_Bracket(char c);//检测是否为右括号，是则返回1，否则返回0
int isFull(StaPtr sta);//判满
int isEmpty(StaPtr sta);//判空
StaPtr Creat_Stack(int Capacity);//栈的创建
void Dispose_Stack(StaPtr sta);//栈的释放
void push(element tmp, StaPtr sta);//入栈
element Top_Element(StaPtr sta);//返回栈顶元素
void pop(StaPtr sta);//出栈
element Top_Pop_Element(StaPtr sta);//出栈并返回出栈元素
char* Get_Line(void);//从标准输入里读取一行最大容量MAXCAP的字符并返回指针
char* Get_Sting(void);//从标准输入里读取一段以#结尾的字符串
void PRINT_SENTENCE(char* src, int* flag);//打印最后补充括号后的表达式