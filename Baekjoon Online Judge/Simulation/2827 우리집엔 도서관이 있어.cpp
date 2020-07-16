#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; 

	cin >> n;

	vector<int> arr;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int norm = n;
	int cnt=0;

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == norm) {
			cnt++;
			norm--;
		}
	}

	cout << n - cnt;

	return 0;
}