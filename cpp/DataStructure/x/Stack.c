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

//스택의 초기화를 진행한다.
//스택 생성 후 제일 먼저 호출되어야 하는 함수이다.
void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;//topIndex의 -1은 빈 상태를 의미함.
}

//스택이 빈경우 TRUE를, 그렇지 않은 경우 FALSE를 반환한다.
int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)//스택이 비어있다면
		return TRUE;
	else
		return FALSE;
}

//스택 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
void SPush(Stack *pstack, Data data)
{
	pstack->topIndex += 1; //데이터 추가를 위한 인덱스 값 증가
	pstack->stackArr[pstack->topIndex] = data; //데이터 값 저장
}

//마지막에 저장된 요소를 삭제한다.
//삭제된 데이터는 반환이 된다.
//본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
Data SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))//스택이 비었는지 확인!
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex; //삭제할 데이터가 저장된 인덱스 값 저장
	pstack->topIndex -= 1; //pop 연산의 결과로 topIndex 값 하나 감소

	return pstack->stackArr[rIdx]; //삭제되는 데이터 반환 
}

//마지막에 저장된 요소를 반환하되 삭제하지 않는다.
//본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))//스택이 비었는지 확인!
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex]; // 맨 위에 저장된 데이터 반환
}

int main()
{
	//Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack);

	//데이터 넣기//	
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	//데이터 꺼내기//
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}