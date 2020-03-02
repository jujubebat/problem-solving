#include<iostream>
#include<string>
using namespace std;


int main() {
	string s;
	int arr[26] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (arr[idx] == -1) {
			arr[idx] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}