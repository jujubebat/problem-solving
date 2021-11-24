#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int T;
	string s;
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		getline(cin,s);
		stack<char> st;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] != ' ') {
				st.push(s[j]);
				if (s.length() - 1 == j) {
					while (!st.empty()) {
						printf("%c", st.top());
						st.pop();
					}
					printf(" ");
				}
			}
			else if(s[j] == ' ' || j == s.length()-1){
				while (!st.empty()) {
					printf("%c", st.top());
					st.pop();
				}
				printf(" ");
			}
		}
		puts("");
	}
}