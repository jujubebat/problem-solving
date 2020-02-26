#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int N;
	int num;
	cin >> N;
	
	for (int i = 1; i <= 1000000; i++) {
		int sum = 0;
		num = i;
		sum += num;
		while (num) {
			sum += num % 10;
			num /= 10;
		}

		if (sum == N) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
}