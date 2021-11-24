#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define QUE_LEN 100

typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

//ť�� �ʱ�ȭ�� �����Ѵ�.
//ť ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ��̴�.
void QueueInit(Queue *pq)// ť�� �� �� ��� front�� rear�� ������ġ ����Ŵ
{
	pq->front = 0;
	pq->rear = 0;
}

//ť�� �� ��� TRUE(1)��, �׷��� ���� ��� FALSE(0)�� ��ȯ�Ѵ�.
int QIsEmpty(Queue *pq)
{
	if (pq->front == pq->rear) // ť�� �� ����ٸ�
		return TRUE;
	else
		return FALSE;
}

//ť�� ���� ��ġ�� �ش��ϴ� �ε��� ���� ��ȯ�Ѵ�.
int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

//ť�� �����͸� �����Ѵ�. �Ű����� data�� ���޵� ���� �����Ѵ�.
void Enqueue(Queue *pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)// ť�� ��á�ٸ�,
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear); // rear�� �� ĭ �̵�
	pq->queArr[pq->rear] = data; // rea�� ����Ű�� ���� ������ ����
}

//��������� ���� �ռ� �����͸� �����Ѵ�.
//������ �����ʹ� ��ȯ�ȴ�.
//�� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�. 
Data Dequeue(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front); // front�� �� ĭ �̵�
	return pq->queArr[pq->front]; // front�� ����Ű�� ������ ��ȯ
}

//��������� ���� �ռ� �����͸� ��ȯ�ϵ� �������� �ʴ´�.
//�� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�. 
Data QPeek(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

//����ť
//front�� rear�� ���� ��ġ�� ����Ű��, ť�� �����
//rear ����ĭ�� front��� ť�� ���� ����
//enqueue ���� ��, rear�� ����Ű�� ��ġ�� �� ĭ �̵���Ų ������, R�� ����Ű�� ��ġ�� �����͸� ����
//dequeue  ���� ��, front�� ����Ű�� ��ġ�� �� ĭ �̵���Ų ������, front�� ����Ű�� ��ġ�� �����
//�����͸� ��ȯ �� �Ҹ���
int main()
{
	//Queue�� ���� �� �ʱ�ȭ//
	Queue q;
	QueueInit(&q);

	//������ �ֱ�//
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QIsEmpty(&q))
	{
		printf("%d ", Dequeue(&q));
	}

	return 0;

}