#include<iostream>
#include<string>	
#include<stack>

using namespace std;

bool check(string s) {

	bool alpabet[30] = { false };
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (!st.empty()) {
			if (alpabet[s[i] - 'a'] && st.top()==s[i]) {
				st.push(s[i]);
			}
			else if (!alpabet[s[i] - 'a']) {
				alpabet[s[i] - 'a'] = true;
				st.push(s[i]);
			}else
				return false;
		}
		else {
			alpabet[s[i] - 'a'] = true;
			st.push(s[i]);
		}
	}

	return true;
}

int main() {
	int t;
	int ans = 0;
	string s;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> s;
		if (check(s))
			ans++;
	}

	printf("%d", ans);

	return 0;
}