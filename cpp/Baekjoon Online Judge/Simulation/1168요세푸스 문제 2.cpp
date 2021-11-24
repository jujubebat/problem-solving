#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	vector<int> arr;
	vector<int> ret;

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	int idx = 0;

	while (arr.size() != 0) {
		idx = (idx + k - 1) % arr.size();
		ret.push_back(arr[idx]);
		arr.erase(arr.begin() + idx);
	}

	cout << "<";
	for (int i = 0; i < ret.size()-1; i++) {
		cout << ret[i] << ", ";
	}
	cout << ret[ret.size() - 1];
	cout << ">";

	return 0;
}