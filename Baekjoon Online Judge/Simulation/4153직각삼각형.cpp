#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		a *= a, b *= b, c *= c;

		if (a == b + c || b == a + c || c == a + b)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}

	return 0;
}