#include<iostream>
using namespace std;

int main() {
	int second = 0;

	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		second += t;
	}

	cout << second / 60 << endl;
	cout << second % 60 << endl;

	return 0;
}