#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST 0//1������뺯������ģʽ��0��֮
#define DEBUG 1//1�������ģʽ��0��֮
#define WHETHER_PRINT 0//1����ͨ����ӡ���ԣ�0��֮
//�ύʱ��������Ӧͬʱ����
#define PROGRAM_MODE 2//1������Ŀһ��2������Ŀ����ֻ���Ƕ���֮һ
#define MAXCAP 200//����ջ���������
#define EmptyTop -1//�����ջʱtop��ֵ

typedef char element;

typedef struct STACK {
    element* Array;
    int top;//����ջ��Ԫ��
    int capacity;//ջ������
}Stack, * StaPtr;

typedef struct NODE
{
    element Content;
    struct NODE* next;
}Node, * NodePtr;
typedef struct QUEUE
{
    NodePtr front;
    NodePtr end;
}Queue, * QueuePtr;

StaPtr Find_First_Bracket(char* src, int len);//�ҵ�����һ�������ţ�����ʼ��ջ
int Find_Bracket(StaPtr s, char* src, int len);//���������ҵ���һ��������
int Find_Operator(StaPtr s, char* src, int len);//���������ҵ���һ�������
int Add_Bracket(StaPtr s, char* src, int* flag, int len);//ջ��Ϊ�����ʱ������������Ų���
int Is_Operator(char c);//����Ƿ�������������򷵻�1�����򷵻�0
int Is_Bracket(char c);//����Ƿ�Ϊ�����ţ����򷵻�1�����򷵻�0
int Judge_Ret(StaPtr s, QueuePtr que);//����Ƿ�Ϊ�������У����򷵻�1�����򷵻�0
int isFull(StaPtr sta);//����
int isEmpty(StaPtr sta);//�п�
StaPtr Creat_Stack(int Capacity);//ջ�Ĵ���
void Dispose_Stack(StaPtr sta);//ջ���ͷ�
void push(element tmp, StaPtr sta);//��ջ
element Top_Element(StaPtr sta);//����ջ��Ԫ��
void pop(StaPtr sta);//��ջ
element Top_Pop_Element(StaPtr sta);//��ջ�����س�ջԪ��
void PRINT_STACK(StaPtr sta);//��ӡջ������Ԫ��
QueuePtr Create_Queue(void);//����һ���ն���
void push_que(element tmp, QueuePtr que);//�����
void pop_que(QueuePtr que);//������
element Top_Que(QueuePtr que);//ȡ������Ԫ��
element Top_Pop_Que(QueuePtr que);//�����в����س�����Ԫ��
int Que_Empty(QueuePtr que);//�����п�
void Dispose_Que(QueuePtr que);//�ͷŶ���
void PRINT_QUE(QueuePtr que);//��ӡ���е�����Ԫ��
char* Get_Line(void);//�ӱ�׼�������ȡһ���������MAXCAP���ַ�������ָ��
int Get_Chars(StaPtr s, QueuePtr que);//�ӱ�׼�����ж�ȡ��#��β���ַ���
void PRINT_SENTENCE(char* src, int* flag);//��ӡ��󲹳����ź�ı��ʽ