#include <string>
#include <vector>
#include<stack>
using namespace std;

bool isRigt(string s) { // 인자 s가 올바른 문자열인지 판별해준다. 
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			if (!st.empty() && st.top() == '(')
				st.pop();
			else
				st.push(s[i]);
		}
		else {
			st.push(s[i]);
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}

string solve(string w) {
	if (w == "") return ""; // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
	
	string u, v;
	stack<char> st;
	int idx;

	// 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
	// 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, 
	// v는 빈 문자열이 될 수 있습니다.
	int left = 0, right = 0;

	for (int i = 0; w.size(); i++) {
		if (w[i] == '(') left++;
		else if (w[i] == ')') right++;

		if (left != 0 && right != 0) {
			if (left == right) {
				idx = i;
				break;
			}
		}
	}

	u = w.substr(0, idx+1);
	v = w.substr(idx + 1);

	// 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
	if (isRigt(u)) 
		return u + solve(v); // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
	else{ // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
		
		string tmp = "("; // 4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
		// 4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
		tmp += solve(v); 
		tmp += ")"; // 4-3. ')'를 다시 붙입니다.

		string newU = "";
		// 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
		for (int i = 1; i < u.size()-1; i++) {
			if (u[i] == '(')
				newU += ")";
			else
				newU += "(";
		}
		return tmp + newU; // 4-5. 생성된 문자열을 반환합니다.
	}
}

string solution(string p) {
	string answer = "";
	answer = solve(p);
	return answer;
}