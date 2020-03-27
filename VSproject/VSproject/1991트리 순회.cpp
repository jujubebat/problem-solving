#include<iostream>
using namespace std;

class TreeNode {

	public :
		char value;
		TreeNode *left;
		TreeNode *right;

		TreeNode(char input) {
			value = input;
		}
};

void inorder(TreeNode* cur) {
	if (cur) {
		inorder(cur->left);
		cout << cur->value;
		inorder(cur->right);
	}
}

void preorder(TreeNode *cur) {
	if (cur) {
		cout << cur->value;
		preorder(cur->left);
		preorder(cur->right);
	}
}

void postorder(TreeNode *cur) {
	if (cur) {
		postorder(cur->left);
		postorder(cur->right);
		cout << cur->value;
	}
}

int main() {
	int n;
	TreeNode *cache[26];
	cin >> n;

	for (int i = 0; i < 26; i++) {
		cache[i] = new TreeNode('A' + i);
	}

	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.') {
			cache[a - 'A']->left = cache[b - 'A'];
		}

		if (c != '.') {
			cache[a - 'A']->right = cache[c - 'A'];
		}
	}

	preorder(cache[0]);
	puts("");
	inorder(cache[0]);
	puts("");
	postorder(cache[0]);

	return 0;
}