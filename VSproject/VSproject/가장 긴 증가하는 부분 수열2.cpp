#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[1000000];

int main() {
	int n;
	cin >> n;

	vector<int> v;
	v.push_back(0);

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num > v.back())
			v.push_back(num);
		else {
			auto it = lower_bound(v.begin(), v.end(), num);
			*it = num;
		}
	}

	cout << v.size()-1;
	return 0;
}