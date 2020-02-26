#include<stdio.h>
#include<stdlib.h>

typedef int BTData;
typedef BTData BSTData;

typedef struct _bTreeNode 
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

//이진 트리 노드를 생성하여 그 주소 값을 반환한다.
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

//노드에 저장된 데이터를 반환한다.
BTData GetData(BTreeNode *bt)
{
	return bt->data;
}

//노드에 데이터를 저장한다. data로 전달된 값을 저장한다.
void SetData(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

//왼쪽 서브 트리의 주소 값을 반환한다. 
BTreeNode* GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

//오른쪽 서브 트리의 주소 값을 반환한다.
BTreeNode* GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

//왼쪽 서브 트리를 연결한다.
void MakeLeftSubTree(BTreeNode * main, BTreeNode *sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

//오른쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode * main, BTreeNode *sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}


//이진트리의 순회 - 트리구조는 그 구조가 재귀적이기 때문에 순회역시 재귀적으로 하면 된다.

//중위 순회 : 루트 노드를 중간에 조회
void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)//bt가 NULL이면 재귀 탈출!
		return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

//전위 순회 : 루트 노드를 먼저 조회
void PreorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	printf("%d \n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

//후위 순회 : 루트 노드를 맨 마지막에 조회 
void PostorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d \n", bt->data);
}

int main()
{
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();

	SetData(bt1, 1);//bt1에 1 저장
	SetData(bt2, 2);//bt2에 2 저장
	SetData(bt3, 3);//bt3에 3저장
	SetData(bt4, 4);//bt4에 4저장

	MakeLeftSubTree(bt1, bt2);//bt2를 bt1의 왼쪽 자식 노드로
	MakeRightSubTree(bt1, bt3);//bt3를 bt1의 오른쪽 자식 노드로
	MakeLeftSubTree(bt2, bt4);//bt4를 bt2의 왼쪽 자식 노드로

	//bt1의 왼쪽 자식 노드의 데이터 출력
	printf("%d \n", GetData(GetLeftSubTree(bt1)));

	//bt1의 왼쪽 자식노드의 왼쪽자식 노드의 데이터 출력 
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	puts("");
	InorderTraverse(bt1); //중위순회

	puts("");
	PreorderTraverse(bt1); //전위순회

	puts("");
	PostorderTraverse(bt1); //후위순회 

	return 0;
}