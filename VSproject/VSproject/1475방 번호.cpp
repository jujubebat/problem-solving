#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	int arr[10] = { 0 };
	int res = -1;
	cin >> s;

	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (i != 6 && i != 9) {
			res = max(res, arr[i]);
		}
	}
	int tmp = arr[6] + arr[9];
	res = max(res, tmp / 2 + tmp % 2);

	cout << res;

	return 0;
}