#include "Experiment2.h"

int isFull(StaPtr sta)//����
{
    if (sta == NULL) exit(1);
    else return(sta->top == sta->capacity - 1);
}
int isEmpty(StaPtr sta)//�п�
{
    if (sta == NULL) exit(1);
    else return(sta->top == EmptyTop);
}
StaPtr Creat_Stack(int Capacity)//ջ�Ĵ���
{
    StaPtr RetPtr = (StaPtr)malloc(sizeof(Stack));
    if (RetPtr == NULL) exit(1);
    RetPtr->top = EmptyTop;
    RetPtr->capacity = Capacity;
    RetPtr->Array = (element*)malloc(sizeof(element) * Capacity);
    if (RetPtr->Array == NULL) exit(1);

    return (RetPtr);
}
void Dispose_Stack(StaPtr sta)//ջ���ͷ�
{
    if (sta != NULL)
    {
        free(sta->Array);
        free(sta);
        if(TEST) printf("Stack cleared\n");
    }
}
void push(element Tmp, StaPtr sta)//��ջ
{
    if (!isFull(sta))
        sta->Array[++sta->top] = Tmp;
    else
        printf("Stack Full!!\n!");
}
element Top_Element(StaPtr sta)//����ջ��Ԫ��
{
    return (sta->Array[sta->top]);
}
void pop(StaPtr sta)//��ջ
{
    if (!isEmpty(sta))
        sta->top--;
    else
        printf("Stack Empty!!!\n");
}
element Top_Pop_Element(StaPtr sta)//��ջ�����س�ջԪ��
{
    if (!isEmpty(sta))
        return (sta->Array[sta->top--]);
    else
    {
        printf("Stack Empty!!!\n");
        exit(1);
    }
}
void PRINT_STACK(StaPtr sta)//��ӡջ������Ԫ��
{
    for (int i = 0; i <= sta->top; i++)
    {
        printf("%c\n", sta->Array[i]);
    }
}