#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	bool start = false;
	int cnt = 0;

	getline(cin, s);
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] != ' ') {
			start = true;
			if (i == len - 1) {
				cnt++;
				break;
			}
		}
		else if (start && s[i] == ' ' ){
			cnt++;
			start = false;
		}
	}
	cout << cnt;
}