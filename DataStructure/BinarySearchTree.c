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

/**************삽입, 탐색 ****************/

void BSTMakeAndInit(BTreeNode **pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode *pNode = NULL; //parent Node
	BTreeNode *cNode = *pRoot; // current Node
	BTreeNode *nNode = NULL; // new Node
	
	//새로운 노드가 추가될 위치를 찾는다.
	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return; // 데이터의 중복을 허용하지 않음

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode(); // 새 노드의 생성
	SetData(nNode, data); // 새 노드에 데이터 저장

	//pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL)// 새 노드가 루트 노드가 아니라면,
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // 새 노드가 루트 노드라면,
	{
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode *bst, BSTData target)
{
	BTreeNode *cNode = bst; // current node
	BSTData cd; // current data;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL; // 탐색대상이 저장되어 있지 않음
}

int main()//삽입, 탐색까지 구현함.
{
	BTreeNode *bstRoot;
	BTreeNode *sNode; // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 데이터의 값 : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 데이터의 값 : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 데이터의 값 : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 데이터의 값 : %d \n", BSTGetNodeData(sNode));

}