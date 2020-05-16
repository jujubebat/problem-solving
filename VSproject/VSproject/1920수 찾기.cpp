#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int a[100000];
int n, m;

bool isExist(int num) {
	int low = 0, high = n-1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == num) {
			return true;
		}
		else if (a[mid] < num) {
			low = mid + 1;
		}
		else if (a[mid] > num) {
			high = mid - 1;
		}
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		if (isExist(num))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}