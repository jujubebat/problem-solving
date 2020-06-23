#include<iostream>
#include<vector>

using namespace std;

int main() {
	int arr[100] = { 3, 5, 7,9, 1 };
	int check[101] = { 0 };

	for (int i = 0; i < 5; i++) {
		check[arr[i]]++;
	}

	vector<int> ret;
	for (int i = 1; i <= 100; i++) {
		if (check[i] >= 2)
			ret.push_back(check[i]);
	}

	if (ret.size() == 0)
		cout << -1 << endl;
	else {
		for (int x : ret)
			cout << x << " ";
	}

	return 0;
}