#include<iostream>
using namespace std;

bool check[31];

int main() {

	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		check[num] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!check[i])
			cout << i << endl;
	}

	return 0;
}