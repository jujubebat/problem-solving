#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;

	cin >> n;

	while (n--) {

		string a, b;
		cin >> a >> b;

		cout << "Distances:";

		for (int i = 0; i < a.size(); i++) {

			int x = a[i] - 'A' + 1;
			int y = b[i] - 'A' + 1;

			if (y >= x) {
				cout << " " << y - x;
			}
			else {
				cout << " " << y + 26 - x;
			}
		}
		cout << endl;
	}

	return 0;
}