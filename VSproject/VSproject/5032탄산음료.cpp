#include<iostream>
using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;

	int bottle = e + f;

	int ret = 0;

	while (bottle >= c) {
		ret += bottle / c;
		bottle = bottle % c + bottle / c;
	}

	cout << ret;

	return 0;
}