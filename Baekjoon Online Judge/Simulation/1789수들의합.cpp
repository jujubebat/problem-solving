#include<iostream>
using namespace std;

int main() {
	long long n;

	cin >> n;

	long long sum = 0;

	for (long long i = 1; ;i++) {
		sum += i;
		if (sum > n) {
			cout << i - 1;
			return 0;
		}
	}

	return 0;
}