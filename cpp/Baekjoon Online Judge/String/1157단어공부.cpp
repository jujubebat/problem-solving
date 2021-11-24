#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[26];

int main() {
	string s;
	
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {//소문자
			arr[s[i] - 'a'] += 1;
		}
		else {//대문자
			arr[s[i] - 'A'] += 1;
		}
	}

	char res;
	int maxVal = -1;

	for (int i = 0; i < 26; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
			res = 'A' + i;
		}
		else if (arr[i] == maxVal) {
			res = '?';
		}
	}
	cout << res;
	return 0;
}