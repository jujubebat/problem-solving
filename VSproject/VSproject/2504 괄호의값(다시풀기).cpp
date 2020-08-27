#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	
	stack<char> st;
	string str;
	int tmp = 1;
	int ret = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '(') {
			tmp *= 2;
			st.push('(');
		}
		else if (str[i] == '[') {
			tmp *= 3;
			st.push('[');
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(')
				ret += tmp;

			if (!st.empty()) st.pop();
				
			tmp /= 2;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[')
				ret += tmp;

		if (!st.empty()) st.pop();

			tmp /= 3;
		}
		else if (str[i] == ')' && (st.empty() || st.top() != '(')) {
			cout << 0;
			return 0;
		}
		else if (str[i] == ']' && (st.empty() || st.top() != '[')) {
			cout << 0;
			return 0;
		}
	}

	if (!st.empty())
		cout << 0;
	else
		cout << ret;

	return 0;
}