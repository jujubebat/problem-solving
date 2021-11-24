#include<iostream>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int yes, no;
		yes = a + b + c + d;
		no = 4 - yes;

		if (no == 1 && yes == 3) {
			cout << 'A' << endl;
		}
 		else if (no == 2 && yes == 2) {
			cout << 'B' << endl;
		}
		else if (no == 3 && yes == 1) {
			cout << 'C' << endl;
		}
		else if (no == 4) {
			cout << 'D' << endl;
		}
		else if (yes == 4) {
			cout << 'E' << endl;
		}
		
	}

	return 0;
}