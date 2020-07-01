#include<iostream>
#include<cstdio>
using namespace std;

int main() {

	int t;

	cin >> t;

	while (t--) {
		int ccase;
		cin >> ccase;

		int retC = 0;
		double retG = 0;

		for (int i = 0; i < ccase; i++) {
			double c;
			double g;

			cin >> c >> g;

			retC += c;
			retG += c*g;
		}

		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(1);
		cout << retC << " " << retG / (double)retC << endl;
	}

	return 0;
}