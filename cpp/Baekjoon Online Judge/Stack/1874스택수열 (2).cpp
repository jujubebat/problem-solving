//스택과 큐의 특성을 활용하여 풀이.
//스택에서 top을 조회할때 스택 empty 여부를 체크 해줘야 오류가 안남.
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