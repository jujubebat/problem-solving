#include<iostream>
#include<algorithm>
using namespace std;

int note1[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {

		int n;

		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> note1[j];
		}

		sort(note1, note1 + n);

		int m;

		cin >> m;

		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;

			int low = 0, high = n - 1;
			bool flag = false;
			
			while (low <= high) {
				int mid = (low + high) / 2;

				if (note1[mid] == num) {
					flag = true;
					break;
				}
				else if (note1[mid] < num) {
					low = mid + 1;
				}
				else if (note1[mid] > num) {
					high = mid - 1;
				}
			}
			
			if (flag)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";

		}
		
	}
	return 0;
}