#include<iostream>
using namespace std;

int main() {
	int n, w, h;

	cin >> n >> w >> h;

	for (int i = 0; i < n; i++) {
		int fire;
		cin >> fire;

		if (fire * fire <= w*w + h*h)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}