#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

//������ �ʱ�ȭ�� �����Ѵ�.
//���� ���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ��̴�.
void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;//topIndex�� -1�� �� ���¸� �ǹ���.
}

//������ ���� TRUE��, �׷��� ���� ��� FALSE�� ��ȯ�Ѵ�.
int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)//������ ����ִٸ�
		return TRUE;
	else
		return FALSE;
}

//���� �����͸� �����Ѵ�. �Ű����� data�� ���޵� ���� �����Ѵ�.
void SPush(Stack *pstack, Data data)
{
	pstack->topIndex += 1; //������ �߰��� ���� �ε��� �� ����
	pstack->stackArr[pstack->topIndex] = data; //������ �� ����
}

//�������� ����� ��Ҹ� �����Ѵ�.
//������ �����ʹ� ��ȯ�� �ȴ�.
//�� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�.
Data SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))//������ ������� Ȯ��!
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex; //������ �����Ͱ� ����� �ε��� �� ����
	pstack->topIndex -= 1; //pop ������ ����� topIndex �� �ϳ� ����

	return pstack->stackArr[rIdx]; //�����Ǵ� ������ ��ȯ 
}

//�������� ����� ��Ҹ� ��ȯ�ϵ� �������� �ʴ´�.
//�� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�.
Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))//������ ������� Ȯ��!
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex]; // �� ���� ����� ������ ��ȯ
}

int main()
{
	//Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	//������ �ֱ�//	
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	//������ ������//
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}