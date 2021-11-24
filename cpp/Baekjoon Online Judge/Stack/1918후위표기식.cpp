#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int getOpPrec(char op) { //연산자의 우선순위 정보 반환
	switch (op){
		case '*':
		case '/':
			return 3;
		case '+':
		case '-':
			return 2;
		case '(':
			return 1;
	}
	return -1;
}

int whoPrecOp(char op1, char op2) {
	int num1 = getOpPrec(op1);
	int num2 = getOpPrec(op2);

	if (num1 > num2) //op1의 우선순위가 더 높다면
		return 1; 
	else if (num1 < num2) //op2의 우선순위가 더 높다면
		return -1;
	else
		return 0; //op1과 op2의 우선순위가 같다면
}

int main() {
	string s;
	stack<char> st;
	vector<char> res;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			res.push_back(s[i]);
		}
		else {
			if (s[i] == '(')
				st.push(s[i]);
			else if (s[i] == ')') {
				while (!st.empty()) {
					if (!st.empty() && st.top() == '(') {
						st.pop();
						break;
					}
					res.push_back(st.top());
					st.pop();
				}
			}
			else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
				
				while (!st.empty() && whoPrecOp(st.top(), s[i]) >= 0) {
					res.push_back(st.top());
					st.pop();
				}

				st.push(s[i]);
			}
		}
	}

	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i];

	return 0;
}

