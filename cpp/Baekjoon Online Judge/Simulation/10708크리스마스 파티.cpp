#include<iostream>
using namespace std;

int score[100];

int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;
	
	int target[100];
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		target[i] = t;
	}

	for (int i = 0; i < m; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			int predict;
			cin >> predict;
			if (predict == target[i])
				score[j]++;
			else
				x++;
		}
		score[target[i]-1] += x;
	}

	for (int i = 0; i < n; i++) {
		cout << score[i] << endl;
	}

	return 0;
}