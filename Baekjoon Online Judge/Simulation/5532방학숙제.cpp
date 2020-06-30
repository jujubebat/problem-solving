#include<iostream>
using namespace std;

int main() {
	int l, a, b, c, d;

	cin >> l;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	int mathDay = b / d;
	
	if (b%d != 0) mathDay++;

	int korDay = a / c;
	
	if (a%c != 0) korDay++;

	if (mathDay > korDay) {
		cout << l - mathDay;
	}
	else {
		cout << l - korDay;
	}

	return 0;
}