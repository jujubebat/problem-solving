#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ret = 0;

	for (int r = 1; r <= n; r++) {
		for (int c = r; r*c <= n; c++) {
			ret++;
		}
	}

	cout << ret;
	return 0;
}