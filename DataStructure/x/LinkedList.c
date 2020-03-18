#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node *next;
}Node;

typedef struct _linkedList
{
	Node *head; //더미 노드를 가리키는 멤버
	Node *cur; // 참조 및 삭제를 돕는 멤버
	Node *before; // 삭제를 돕는 멤버
	int numOfData; //저장된 데이터의 수를 기록하기 위한 멤버
	int(*comp)(LData d1, LData d2); // 정렬의 기준을 등록하기 위한 멤버
}LinkedList;

typedef LinkedList List;

//초기화할 리스트의 주소 값을 이자로 전달한다.
//리스트 생성 후 제일 먼저 호출되어야 하는 함수이다.
void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드의 생성
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
	newNode->data = data; // 새 노드에 데이터 저장

	newNode->next = plist->head->next; //새 노드가 다른 노드를 가리키게 함
	plist->head->next = newNode; // 더미 노드가 새 노드를 가리키게 함

	(plist->numOfData)++; // 저장된 노드의 수를 하나 증가시킴
}

void SInsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node)); // 새 노드의 생성
	Node *pred = plist->head; // pred는 더미노드를 가리킴

	newNode->data = data; // 새 노드에 데이터 저장

	// 새 노드가 들어갈 위치를 찾기 위한 반복문
	// comp가 0을 반환 : 첫 번째 인자인 data가 정렬 순서상 앞서서 head에 더 가까워야 하는 경우
	while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next; // 다음 노드로 이동
	}

	newNode->next = pred->next; // 새 노드의 오른쪽을 연결
	pred->next = newNode; //새 노드의 왼쪽을 연결

	(plist->numOfData)++; // 저장된 데이터의 수 하나 증가
}

//리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.
void LInsert(List *plist, LData data)
{
	if (plist->comp == NULL) // 정렬기준이 마련되지 않았다면,
		FInsert(plist, data); // 머리에 노드를 추가!
	else					 // 정렬기준이 마련되었다면,
		SInsert(plist, data); // 정렬기준에 근거하여 노드를 추가!
}

//첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
//데이터의 참조를 위한 초기화가 진행된다.
//참조 성공시 TRUE, 실패 시 FALSE 반환
int LFirst(List *plist, LData *pdata)
{
	if (plist->head->next == NULL) // 더미 노드가 NULL을 가리킨다면,
		return FALSE; // 반환할 데이터가 없다!

	plist->before = plist->head; // before은 더미 노드를 가리키게 함
	plist->cur = plist->head->next; // cur은 첫 번째 노드를 가리키게 함

	*pdata = plist->cur->data; // 첫 번째 노드의 데이터를 전달 
	return TRUE; //데이터 반환 성공!
}

//참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
//순차적인 참조를 위해서 반복호출이 가능하다.
//참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다.
//참조 성공시 TRUE, 실패시 FALSE 반환
int LNext(List *plist, LData *pdata)
{
	if (plist->cur->next == NULL) // cur이 NULL을 가리킨다면,
		return FALSE; //반환할 데이터가 없다!

	plist->before = plist->cur; // cur이 가리키던 것을 before가 가리킴
	plist->cur = plist->cur->next; //cur은 그 다음 노드를 가리킴

	*pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 전달
	return TRUE; //데이터 반환 성공!
}

//LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
//삭제된 데이터는 반환된다.
//마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.
LData LRemove(List *plist)
{
	Node *rpos = plist->cur; // 소멸 대상의 주소 값을 rpos에 저장
	LData rdata = rpos->data; // 소멸 대상의 데이터를 rdata에 저장

	plist->before->next = plist->cur->next; // 소멸 대상을 리스트에서 제거
	plist->cur = plist->before; // cur이 가리키는 위치를 재조정!

	free(rpos); //리스트에서 제거된 노드 소멸
	(plist->numOfData)--; //저장된 데이터의 수 하나 감소
	return rdata; // 제거된 노드의 데이터 반환
}

int LCount(List *plist)
{
	return plist->numOfData; //저장된 데이터의 수 반환
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0; //d1이 정렬 순서상 앞선다.
	else
		return 1; //d2가 정렬 순서상 앞서거나 같다.
}

int main()
{
	//리스트의 생성 및 초기화//
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	//5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	//저장된 데이터의 전체 출력//
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22을 검색하여 모두 삭제//
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	//삭제 후 남아있는 데이터 전체 출력 //
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
