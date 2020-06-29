#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	vector<pair<int, int>> arr;

	for (int i = 1; i <= 5; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr.push_back({ a + b + c + d , i });
	}

	sort(arr.begin(), arr.end());

	cout << arr.back().second << " " << arr.back().first << endl;

	return 0;
}