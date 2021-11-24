//���ð� ť�� Ư���� Ȱ���Ͽ� Ǯ��.
//���ÿ��� top�� ��ȸ�Ҷ� ���� empty ���θ� üũ ����� ������ �ȳ�.
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main() {
	int n, num;
	queue<int> q;
	vector<char> res;
	stack<int> st;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		q.push(num);
	}

	num = 1;
	while (num <= n) {
		st.push(num);
		res.push_back('+');
		while (!st.empty() && st.top() == q.front()) {
			st.pop();
			res.push_back('-');
			q.pop();
		}
		num++;
	}

	if (st.empty()) {
		for (int i = 0; i < res.size(); i++)
			printf("%c\n", res[i]);
	}
	else {
		printf("NO");
	}
}