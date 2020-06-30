#include<iostream>
using namespace std;

int main() {
	int a, b, c, d, p;

	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> p;

	int xPrice, yPrice;

	xPrice = a * p;

	if (p <= c) {
		yPrice = b;
	}
	else {
		yPrice = b + (p - c) * d;
	}

	if (xPrice < yPrice)
		cout << xPrice;
	else
		cout << yPrice;

	return 0;
}