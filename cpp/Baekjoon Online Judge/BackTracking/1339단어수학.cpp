#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int alpabet[26];

int main() {
	int n;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int size = s.length();
		for (int j = 0; j < size; j++) {
			alpabet[s[j] - 'A'] += pow(10, size - j - 1);
		}
	}
	sort(alpabet, alpabet + 26, greater<int>());
	int num = 9, res = 0;
	for (int i = 0; i < 26; i++) {
		if (alpabet[i]) {
			res += num * alpabet[i];
			num--;
		}
	}
	printf("%d", res);
	return 0;
}