#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> l, r;

int main() {
	string s;

	cin >> s;

	//초기 커서위치는 문장의 맨 뒤이므로 l 스택에 모든 문자열을 넣는다.
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

	while (!l.empty()) { //l스택의 원소들을 r스택에 넣어주어 결과를 만든다.
		r.push(l.top());
		l.pop();
	}

	while (!r.empty()) {//결과 출력 top부터 출력 하면된다. (l에서 r로 넘어왔기 때문에 순서가 올바르다.)
		cout << r.top();
		r.pop();
	}

	return 0;
}