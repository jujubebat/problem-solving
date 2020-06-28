#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s) {
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (st.empty()) {
			st.push(s[i]);
		}
		else {
			if (s[i] == st.top()) {
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}
	}

	if (st.size() == 0)
		return 1;
	else
		return 0;
}

