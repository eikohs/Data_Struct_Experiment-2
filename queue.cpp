#include "Experiment2.h"

QueuePtr Create_Queue(void)//����һ���ն���
{
	QueuePtr RetPtr = (QueuePtr)malloc(sizeof(QUEUE));
	if (RetPtr == NULL) exit(1);
	else RetPtr->front = RetPtr->end = NULL;

	return RetPtr;
}
void push_que(element tmp, QueuePtr que)//�����
{
	if (Que_Empty(que))//û�г�ʼ��ʱ���г�ʼ���������
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
void pop_que(QueuePtr que)//������
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
int Que_Empty(QueuePtr que)//�����п�
{
	return (que->front == NULL&&que->end == NULL);
}
void Dispose_Que(QueuePtr que)//�ͷŶ���
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
element Top_Que(QueuePtr que)//ȡ������Ԫ��
{
	return(que->front->Content);
}
element Top_Pop_Que(QueuePtr que)//�����в����س�����Ԫ��
{
	element RetVal = que->front->Content;
	pop_que(que);
	return RetVal;
}
void PRINT_QUE(QueuePtr que)//��ӡ���е�����Ԫ��
{
	NodePtr tmp = que->front;
	while (tmp != NULL)
	{
		printf("%c\n", tmp->Content);
		tmp = tmp->next;
	}
}