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

//큐의 초기화를 진행한다.
//큐 생성 후 제일 먼저 호출되어야 하는 함수이다.
void QueueInit(Queue *pq)// 큐가 텅 빈 경우 front와 rear은 동일위치 가리킴
{
	pq->front = 0;
	pq->rear = 0;
}

//큐가 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.
int QIsEmpty(Queue *pq)
{
	if (pq->front == pq->rear) // 큐가 텅 비었다면
		return TRUE;
	else
		return FALSE;
}

//큐의 다음 위치에 해당하는 인덱스 값을 반환한다.
int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

//큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
void Enqueue(Queue *pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)// 큐가 꽉찼다면,
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear); // rear을 한 칸 이동
	pq->queArr[pq->rear] = data; // rea이 가리키는 곳에 데이터 저장
}

//저장순서가 가장 앞선 데이터를 삭제한다.
//삭제된 데이터는 반환된다.
//본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다. 
Data Dequeue(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front); // front를 한 칸 이동
	return pq->queArr[pq->front]; // front가 가리키는 데이터 반환
}

//저장순서가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
//본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다. 
Data QPeek(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

//원형큐
//front와 rear가 같은 위치를 가리키면, 큐가 빈상태
//rear 다음칸이 front라면 큐가 꽉찬 상태
//enqueue 연산 시, rear가 가리키는 위치를 한 칸 이동시킨 다음에, R이 가리키는 위치에 데이터를 저장
//dequeue  연산 시, front가 가리키는 위치를 한 칸 이동시킨 다음에, front가 가리키는 위치렝 저장된
//데이터를 반환 및 소멸함
int main()
{
	//Queue의 생성 및 초기화//
	Queue q;
	QueueInit(&q);

	//데이터 넣기//
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