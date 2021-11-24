#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

void password(string s) {
	stack<int> left, right;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			if (left.empty()) continue;
			right.push(left.top());
			left.pop();
		}
		else if (s[i] == '>') {
			if (right.empty()) continue;
			left.push(right.top());
			right.pop();
		}
		else if (s[i] == '-') {
			if (left.empty()) continue;
			left.pop();
		}
		else {
			left.push(s[i]);
		}
	}

	string tmp1="", tmp2="";

	while (!left.empty()) {
		tmp1 += left.top();
		left.pop();
	}

	reverse(tmp1.begin(), tmp1.end());

	while (!right.empty()) {
		tmp2 += right.top();
		right.pop();
	}

	cout << tmp1 << tmp2 << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		password(s);
	}
	
	return 0;
}