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

int main()
{
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();

	SetData(bt1, 1);//bt1�� 1 ����
	SetData(bt2, 2);//bt2�� 2 ����
	SetData(bt3, 3);//bt3�� 3����
	SetData(bt4, 4);//bt4�� 4����

	MakeLeftSubTree(bt1, bt2);//bt2�� bt1�� ���� �ڽ� ����
	MakeRightSubTree(bt1, bt3);//bt3�� bt1�� ������ �ڽ� ����
	MakeLeftSubTree(bt2, bt4);//bt4�� bt2�� ���� �ڽ� ����

	//bt1�� ���� �ڽ� ����� ������ ���
	printf("%d \n", GetData(GetLeftSubTree(bt1)));

	//bt1�� ���� �ڽĳ���� �����ڽ� ����� ������ ��� 
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	puts("");
	InorderTraverse(bt1); //������ȸ

	puts("");
	PreorderTraverse(bt1); //������ȸ

	puts("");
	PostorderTraverse(bt1); //������ȸ 

	return 0;
}