#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int d[100001];

int main() {
	int n;
	int res = -100000000;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	d[1] = arr[1];
	res = max(res, d[1]);
	for (int i = 2; i <= n; i++) {
		d[i] = max(arr[i], arr[i] + d[i - 1]);
		res = max(res, d[i]);
	}

	cout << res;
	
	return 0;
}