#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	int norm = 10;

	if (n < norm) {
		cout << n;
		return 0;
	}

	while (n > norm) {

		if (n % norm >= 5 * (norm / 10)) {
			n += norm - (n % norm);
		}
		else {
			n -= n % norm;
		}

		norm *= 10;
	}

	cout << n;

	return 0;
}

