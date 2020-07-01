#include<iostream>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int sh, sm, ss;
		int eh, em, es;

		cin >> sh >> sm >> ss;
		cin >> eh >> em >> es;

		int ret = (eh - sh) * 60 * 60 + (em - sm) * 60 + (es - ss);

		cout << ret / 3600 << " ";
		ret %= 3600;
		cout << ret / 60 << " ";
		cout << ret % 60 << endl;
	}

	return 0;
}