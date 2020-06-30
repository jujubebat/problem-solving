#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int sum = 0;
	int maxValue = 0x7ffffff;
	int ret = -1;

	for (int i = 0; i < 10; i++) {
		int score;
		cin >> score;
		sum += score;

		if (abs(sum - 100) <= maxValue) {
			maxValue = abs(sum - 100);
			ret = max(ret, sum);
		}
	}

	cout << ret;
	return 0;
}