//레이저를 == () 만났을 경우 막대기를 자른다 -> 스택 size를 이용한다.
//계속 고민하다가 풀지 못함. 문제를 다르게 보는 시각이 부족했음

#include<iostream>
#include<stack>
#include<algorithm>	
#include<string>

using namespace std;

int main() {
	stack<char> st;
	string str;
	int res=0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			st.push(str[i]);
		else if (str[i] == ')') {
			st.pop();
			if (str[i - 1] == '(')
				res += st.size();
			else
				res += 1;
		}
	}

	cout << res;
}