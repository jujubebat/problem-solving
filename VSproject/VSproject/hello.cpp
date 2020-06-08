#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v(5, 7);

	for (int x : v) {
		x += 1;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<<" ";
	}

	return 0;
}