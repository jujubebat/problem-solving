#include<iostream>
using namespace std;

int vote[1000];

int main() {
	int n, m;

	cin >> n >> m;

	int game[1000];

	for (int i = 0; i < n; i++) {
		cin >> game[i];
	}

	for (int i = 0; i < m; i++) {
		int person;
		cin >> person;
		for (int j = 0; j < n; j++) {
			if (game[j] <= person) {
				vote[j]++;
				break;
			}
		}
	}

	int ret;
	int maxValue = -1;

	for (int i = 0; i < n; i++) {
		if (vote[i] > maxValue) {
			maxValue = vote[i];
			ret = i + 1;
		}
	}

	cout << ret; 

	return 0;
}