#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		int a, b;

		cin >> a >> b;

		if (b % 4 == 0)
			b = 4;
		else
			b %= 4;

		int ret = (int)pow(a, b) % 10;

		if (ret == 0)
			cout << 10 << endl;
		else
			cout << ret << endl;
			
	}

	return 0;
}
