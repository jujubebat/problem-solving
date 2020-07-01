#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int n; 

	cin >> n;

	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	map<int, int> m;

	for (int i = 0; i < n; i++) {

		for (int j = 1; j <= arr[i]; j++) {

			if (arr[i] % j == 0) {
				m[j]++;
			}

		}
	}

	vector<int> ret;

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == n)
			ret.push_back(it->first);
	}

	sort(ret.begin(), ret.end());

	for (int tmp : ret)
		cout << tmp << endl;

	return 0;
}