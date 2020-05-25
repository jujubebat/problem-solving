/*
정답코드보고 너무 오래걸려서 스킵..

*/

#include<iostream>
#include<string>	
#include<stack>
using namespace std;

string s;
int visited[50];

int solve(int start, int end) {

	cout << start << " " << end << endl;
	int ret = 0;

	for (int i = start; i < end; i++) {

		if (s[i] == '(') {
			int k = s[i - 1] - '0';
			int x = solve(i + 1, visited[i]);
			ret += k * x - 1; // 여기서 -1을 해주는 것이 이해가 안됨
			i = visited[i];
		}
		else 
			ret++;
	}

	return ret;
}

int main() {

	cin >> s;

	stack<int> st;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			visited[st.top()] = i;
			st.pop();
		}
	}

	cout << solve(0, s.length());

	return 0;
}