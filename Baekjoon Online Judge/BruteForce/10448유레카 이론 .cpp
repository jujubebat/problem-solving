#include<iostream>

using namespace std;

int T[1001];

bool isPossible(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
			if (T[i]+T[j]+T[k] == n) return true;
			}
		}
	}
	return false;
}

int main() {
	for (int i = 1; i <= 1000; i++) {
		T[i] = i * (i + 1) / 2;
	}
	
	int t,k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		if (isPossible(k))
			printf("1\n");
		else
			printf("0\n");
	}
}