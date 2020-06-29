#include<iostream>
using namespace std;

int main() {
	int ret = 0;
	int n;

	cin >> n;

	for (int i = 0; i < 5; i++) {
		int carNum;
		cin >> carNum;

		if (carNum % 10 == n)
			ret++;
	}

	cout << ret;

	return 0;
}