#include "Experiment2.h"

QueuePtr Create_Queue(void)//创建一个空队列
{
	QueuePtr RetPtr = (QueuePtr)malloc(sizeof(QUEUE));
	if (RetPtr == NULL) exit(1);
	else RetPtr->front = RetPtr->end = NULL;

	return RetPtr;
}
void push_que(element tmp, QueuePtr que)//入队列
{
	if (Que_Empty(que))//没有初始化时进行初始化和入队列
	{
		que->front = (NodePtr)malloc(sizeof(NODE));
		que->end = que->front;
		que->front->Content = tmp;
		que->end->next = NULL;
	}
	else
	{
		que->end->next = (NodePtr)malloc(sizeof(NODE));
		que->end = que->end->next;
		que->end->Content = tmp;
		que->end->next = NULL;
	}
}
void pop_que(QueuePtr que)//出队列
{
	if (Que_Empty(que)) exit(1);
	else
	{
		NodePtr tmp = que->front;
		que->front = tmp->next;
		free(tmp);
		if (que->front == NULL) que->end = NULL;
	}
}
int Que_Empty(QueuePtr que)//队列判空
{
	return (que->front == NULL&&que->end == NULL);
}
void Dispose_Que(QueuePtr que)//释放队列
{
	NodePtr tmp = que->front;
	while (que->front != que->end)
	{
		que->front = que->front->next;
		free(tmp);
		tmp = que->front;
	}
	free(que->front);
}
element Top_Que(QueuePtr que)//取队列首元素
{
	return(que->front->Content);
}
element Top_Pop_Que(QueuePtr que)//出队列并返回出队列元素
{
	element RetVal = que->front->Content;
	pop_que(que);
	return RetVal;
}
void PRINT_QUE(QueuePtr que)//打印队列的所有元素
{
	NodePtr tmp = que->front;
	while (tmp != NULL)
	{
		printf("%c\n", tmp->Content);
		tmp = tmp->next;
	}
}