#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int arr[100000];
	int res = -1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		res = max(res, arr[i] * (n - i));
	}

	printf("%d", res);
}