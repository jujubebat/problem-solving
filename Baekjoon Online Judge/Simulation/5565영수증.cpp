#include<iostream>
using namespace std;

int main() {

	int total;
	cin >> total;

	for (int i = 0; i < 9; i++) {
		int price;
		cin >> price;
		total -= price;
	}

	cout << total;
	return 0;
}