#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> arr;
	int ret = 0;
	int n, m;

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	int start = 0, end = n - 1;

	while (1) {

		if (arr[start] + arr[end] < m) {
			start++;
		}
		else if (arr[start] + arr[end] >= m) {
			if (arr[start] + arr[end] == m)
				ret++;
			end--;
		}

		if (start == end)
			break;
	}

	cout << ret;

	return 0;
}

