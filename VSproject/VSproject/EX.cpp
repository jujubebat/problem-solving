#include<iostream>
using namespace std;

int main() {
	int arr[15];

	while (1) {
	
		for (int i = 0; i < 16; i++) {
			cin >> arr[i];
			if (arr[i] == -1)
				return 0;
			if (arr[i] == 0)
				break;
		}

		int cnt = 0;
		for (int i = 0; i < 16; i++) {
			if (arr[i] == 0)
				break;
			for (int j = 0; j < 16; j++) {
				if (arr[j] == 0)
					break;
				if (arr[i] == 2 * arr[j]) {
					cnt++;
					break;
				}
			}
		}

		cout << cnt << endl;
	}
}