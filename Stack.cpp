#include "Experiment2.h"

int isFull(StaPtr sta)//判满
{
    if (sta == NULL) exit(1);
    else return(sta->top == sta->capacity - 1);
}
int isEmpty(StaPtr sta)//判空
{
    if (sta == NULL) exit(1);
    else return(sta->top == EmptyTop);
}
StaPtr Creat_Stack(int Capacity)//栈的创建
{
    StaPtr RetPtr = (StaPtr)malloc(sizeof(Stack));
    if (RetPtr == NULL) exit(1);
    RetPtr->top = EmptyTop;
    RetPtr->capacity = Capacity;
    RetPtr->Array = (element*)malloc(sizeof(element) * Capacity);
    if (RetPtr->Array == NULL) exit(1);

    return (RetPtr);
}
void Dispose_Stack(StaPtr sta)//栈的释放
{
    if (sta != NULL)
    {
        free(sta->Array);
        free(sta);
        if(TEST) printf("Stack cleared\n");
    }
}
void push(element Tmp, StaPtr sta)//入栈
{
    if (!isFull(sta))
        sta->Array[++sta->top] = Tmp;
    else
        printf("Stack Full!!\n!");
}
element Top_Element(StaPtr sta)//返回栈顶元素
{
    return (sta->Array[sta->top]);
}
void pop(StaPtr sta)//出栈
{
    if (!isEmpty(sta))
        sta->top--;
    else
        printf("Stack Empty!!!\n");
}
element Top_Pop_Element(StaPtr sta)//出栈并返回出栈元素
{
    if (!isEmpty(sta))
        return (sta->Array[sta->top--]);
    else
    {
        printf("Stack Empty!!!\n");
        exit(1);
    }
}
void PRINT_STACK(StaPtr sta)//打印栈的所有元素
{
    for (int i = 0; i <= sta->top; i++)
    {
        printf("%c\n", sta->Array[i]);
    }
}