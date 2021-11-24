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
	Node *head; //���� ��带 ����Ű�� ���
	Node *cur; // ���� �� ������ ���� ���
	Node *before; // ������ ���� ���
	int numOfData; //����� �������� ���� ����ϱ� ���� ���
	int(*comp)(LData d1, LData d2); // ������ ������ ����ϱ� ���� ���
}LinkedList;

typedef LinkedList List;

//�ʱ�ȭ�� ����Ʈ�� �ּ� ���� ���ڷ� �����Ѵ�.
//����Ʈ ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ��̴�.
void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // ���� ����� ����
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node)); // �� ��� ����
	newNode->data = data; // �� ��忡 ������ ����

	newNode->next = plist->head->next; //�� ��尡 �ٸ� ��带 ����Ű�� ��
	plist->head->next = newNode; // ���� ��尡 �� ��带 ����Ű�� ��

	(plist->numOfData)++; // ����� ����� ���� �ϳ� ������Ŵ
}

void SInsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node)); // �� ����� ����
	Node *pred = plist->head; // pred�� ���̳�带 ����Ŵ

	newNode->data = data; // �� ��忡 ������ ����

	// �� ��尡 �� ��ġ�� ã�� ���� �ݺ���
	// comp�� 0�� ��ȯ : ù ��° ������ data�� ���� ������ �ռ��� head�� �� ������� �ϴ� ���
	while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next; // ���� ���� �̵�
	}

	newNode->next = pred->next; // �� ����� �������� ����
	pred->next = newNode; //�� ����� ������ ����

	(plist->numOfData)++; // ����� �������� �� �ϳ� ����
}

//����Ʈ�� �����͸� �����Ѵ�. �Ű����� data�� ���޵� ���� �����Ѵ�.
void LInsert(List *plist, LData data)
{
	if (plist->comp == NULL) // ���ı����� ���õ��� �ʾҴٸ�,
		FInsert(plist, data); // �Ӹ��� ��带 �߰�!
	else					 // ���ı����� ���õǾ��ٸ�,
		SInsert(plist, data); // ���ı��ؿ� �ٰ��Ͽ� ��带 �߰�!
}

//ù ��° �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
//�������� ������ ���� �ʱ�ȭ�� ����ȴ�.
//���� ������ TRUE, ���� �� FALSE ��ȯ
int LFirst(List *plist, LData *pdata)
{
	if (plist->head->next == NULL) // ���� ��尡 NULL�� ����Ų�ٸ�,
		return FALSE; // ��ȯ�� �����Ͱ� ����!

	plist->before = plist->head; // before�� ���� ��带 ����Ű�� ��
	plist->cur = plist->head->next; // cur�� ù ��° ��带 ����Ű�� ��

	*pdata = plist->cur->data; // ù ��° ����� �����͸� ���� 
	return TRUE; //������ ��ȯ ����!
}

//������ �������� ���� �����Ͱ� pdata�� ����Ű�� �޸𸮿� ����ȴ�.
//�������� ������ ���ؼ� �ݺ�ȣ���� �����ϴ�.
//������ ���� �����Ϸ��� ���� LFirst �Լ��� ȣ���ؾ� �Ѵ�.
//���� ������ TRUE, ���н� FALSE ��ȯ
int LNext(List *plist, LData *pdata)
{
	if (plist->cur->next == NULL) // cur�� NULL�� ����Ų�ٸ�,
		return FALSE; //��ȯ�� �����Ͱ� ����!

	plist->before = plist->cur; // cur�� ����Ű�� ���� before�� ����Ŵ
	plist->cur = plist->cur->next; //cur�� �� ���� ��带 ����Ŵ

	*pdata = plist->cur->data; // cur�� ����Ű�� ����� ������ ����
	return TRUE; //������ ��ȯ ����!
}

//LFirst �Ǵ� LNext �Լ��� ������ ��ȯ �����͸� �����Ѵ�.
//������ �����ʹ� ��ȯ�ȴ�.
//������ ��ȯ �����͸� �����ϹǷ� ������ �ݺ� ȣ���� ������� �ʴ´�.
LData LRemove(List *plist)
{
	Node *rpos = plist->cur; // �Ҹ� ����� �ּ� ���� rpos�� ����
	LData rdata = rpos->data; // �Ҹ� ����� �����͸� rdata�� ����

	plist->before->next = plist->cur->next; // �Ҹ� ����� ����Ʈ���� ����
	plist->cur = plist->before; // cur�� ����Ű�� ��ġ�� ������!

	free(rpos); //����Ʈ���� ���ŵ� ��� �Ҹ�
	(plist->numOfData)--; //����� �������� �� �ϳ� ����
	return rdata; // ���ŵ� ����� ������ ��ȯ
}

int LCount(List *plist)
{
	return plist->numOfData; //����� �������� �� ��ȯ
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0; //d1�� ���� ������ �ռ���.
	else
		return 1; //d2�� ���� ������ �ռ��ų� ����.
}

int main()
{
	//����Ʈ�� ���� �� �ʱ�ȭ//
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	//5���� ������ ����
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	//����� �������� ��ü ���//
	printf("���� �������� �� : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ����//
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

	//���� �� �����ִ� ������ ��ü ��� //
	printf("���� �������� ��: %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
