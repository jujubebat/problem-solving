#include<iostream>
#include<algorithm>
using namespace std;

long long lens[10000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> lens[i];
	}

	long long low = 1, high = 0xffffffff;

	while (low + 1< high) {
		long long mid = (low + high) / 2;
		long long count = 0;

		for (int i = 0; i < k; i++) {
			count += lens[i]/mid;
		}

		if (count >= n) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	cout << low;
	return 0;
}