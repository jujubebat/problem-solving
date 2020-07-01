#include<iostream>
using namespace std;

int main() {

	int n, T;

	cin >> n >> T;

	int cnt = 0;
	int sum = 0;

	while (n--) {
		int score;
		cin >> score;

		cnt++;
		sum += score;
		if (sum > T) {
			cnt--;
			break;
		}
	}

	cout << cnt;

	return 0;
}