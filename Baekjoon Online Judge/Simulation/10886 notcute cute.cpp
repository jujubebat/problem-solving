#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	int cute = 0, notCute = 0;

	for (int i = 0; i < n; i++) {
		int opinion;

		cin >> opinion;

		if (opinion)
			cute++;
		else
			notCute++;
	}

	if (cute > notCute)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";

	return 0;
}