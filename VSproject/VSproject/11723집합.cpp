#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<bitset>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int bit=0;
	int m;

	cin >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		int n;

		if (str == "add") {
			cin >> n;
			bit |= (1 << n - 1);
		}
		else if (str == "remove") {
			cin >> n;
			bit &= ~(1 << n - 1);
		}
		else if (str == "check") {
			cin >> n;
			if (bit & (1 << n - 1))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "toggle") {
			cin >> n;
			bit ^= (1 << n - 1);
		}
		else if (str == "all") {
			bit = 1048576 - 1;
		}
		else if (str == "empty") {
			bit &= 0;
		}

	}

	return 0;
}