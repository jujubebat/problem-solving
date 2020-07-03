#include<iostream>
#include<algorithm>
using namespace std;

int arr[50];
int num[50];

int main() {
	int cnt;
	cin >> cnt;

	int maxValue = -1;

	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
		num[i] = arr[i];
		maxValue = max(maxValue, arr[i]);
	}

	int tmp = maxValue;
	while (1) {

		bool flag = true;
		for (int i = 1; i < cnt; i++) {
			if (arr[i] != arr[i - 1])
				flag = false;
		}
		if (flag) break;

		for (int i = 0; i < cnt; i++) {
			if (arr[i] < maxValue || arr[i] <= tmp) {
				arr[i] += num[i];
				maxValue = max(maxValue, arr[i]);
			}
		}

	}

	cout << arr[0];

	return 0;
}