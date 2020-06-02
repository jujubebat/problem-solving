#include <string>
#include <vector>
#include<stack>
using namespace std;

bool isRigt(string s) {
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
	if (w == "") return "";
	
	string u, v;
	stack<char> st;
	int idx;

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

	if (isRigt(u)) 
		return u + solve(v);
	else{
		string tmp = "(";
		tmp += solve(v);
		tmp += ")";

		string newU = "";
		
		for (int i = 1; i < u.size()-1; i++) {
			if (u[i] == '(')
				newU += ")";
			else
				newU += "(";
		}
		return tmp + newU;
	}
}

string solution(string p) {
	string answer = "";
	answer = solve(p);
	return answer;
}