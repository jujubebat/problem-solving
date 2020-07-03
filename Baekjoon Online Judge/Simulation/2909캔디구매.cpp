#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int c, k;
	cin >> c >> k;

	k = pow(10, k);

	if (c % k >= 5 * (k / 10)) {
		c += k - c % k;
	}else if (c % k < 5 * (k / 10)) {
		c -= c % k;
	}

	cout << c;
	return 0;
}