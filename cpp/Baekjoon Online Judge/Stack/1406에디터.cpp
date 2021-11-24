#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> l, r;

int main() {
	string s;

	cin >> s;

	//�ʱ� Ŀ����ġ�� ������ �� ���̹Ƿ� l ���ÿ� ��� ���ڿ��� �ִ´�.
	for (int i = 0; i < s.size(); i++) {
		l.push(s[i]);
	}

	int m;
	cin >> m;

	char op;
	
	while (m--) {
		cin >> op;
		if (op == 'L' && !l.empty()) {
			r.push(l.top());
			l.pop();
		}
		else if (op == 'D' && !r.empty()) {
			l.push(r.top());
			r.pop();
		}
		else if (op == 'B' && !l.empty()) {
			l.pop();
		}
		else if (op == 'P') {
			char ch; 
			cin >> ch;
			l.push(ch);
		}
	}

	while (!l.empty()) { //l������ ���ҵ��� r���ÿ� �־��־� ����� �����.
		r.push(l.top());
		l.pop();
	}

	while (!r.empty()) {//��� ��� top���� ��� �ϸ�ȴ�. (l���� r�� �Ѿ�Ա� ������ ������ �ùٸ���.)
		cout << r.top();
		r.pop();
	}

	return 0;
}