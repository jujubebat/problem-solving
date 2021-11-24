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

//���� Ʈ�� ��带 �����Ͽ� �� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

//��忡 ����� �����͸� ��ȯ�Ѵ�.
BTData GetData(BTreeNode *bt)
{
	return bt->data;
}

//��忡 �����͸� �����Ѵ�. data�� ���޵� ���� �����Ѵ�.
void SetData(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

//���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�. 
BTreeNode* GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

//������ ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

//���� ���� Ʈ���� �����Ѵ�.
void MakeLeftSubTree(BTreeNode * main, BTreeNode *sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

//������ ���� Ʈ���� �����Ѵ�.
void MakeRightSubTree(BTreeNode * main, BTreeNode *sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}


//����Ʈ���� ��ȸ - Ʈ�������� �� ������ ������̱� ������ ��ȸ���� ��������� �ϸ� �ȴ�.

//���� ��ȸ : ��Ʈ ��带 �߰��� ��ȸ
void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)//bt�� NULL�̸� ��� Ż��!
		return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

//���� ��ȸ : ��Ʈ ��带 ���� ��ȸ
void PreorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	printf("%d \n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

//���� ��ȸ : ��Ʈ ��带 �� �������� ��ȸ 
void PostorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d \n", bt->data);
}

/**************����, Ž�� ****************/

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
	
	//���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return; // �������� �ߺ��� ������� ����

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode(); // �� ����� ����
	SetData(nNode, data); // �� ��忡 ������ ����

	//pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL)// �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // �� ��尡 ��Ʈ �����,
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

	return NULL; // Ž������� ����Ǿ� ���� ����
}

int main()//����, Ž������ ������.
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
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ �������� �� : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ �������� �� : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ �������� �� : %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ �������� �� : %d \n", BSTGetNodeData(sNode));

}