#include<iostream>
using namespace std;

bool Eratosthenes[246913];

int getPrimeNumCount(int n) {

	int count = 0;

	for (int i = n + 1; i <= 2*n; i++) {
		if (!Eratosthenes[i]) count++;
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i < 246913; i++) {
		if (Eratosthenes[i]) continue;
		for (int j = 2; i*j < 246913; j++) {
			Eratosthenes[i*j] = true;
		}
	}

	int n;

	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << getPrimeNumCount(n) << endl;
	}

	return 0;
}