#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int ret = 0;
	int n;
	cin >> n;

	while (n--) {
		stack<char> st;
		string str;
		
		cin >> str;

		for (int i = 0; i < str.size(); i++) {

			if (st.empty())
				st.push(str[i]);
			else if (!st.empty() && st.top() == str[i]) {
				st.pop();
			}
			else
				st.push(str[i]);
		}

		if (st.empty()) ret++;
	}

	cout << ret;

	return 0;
}