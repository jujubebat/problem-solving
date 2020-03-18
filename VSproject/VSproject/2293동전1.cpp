#include<iostream>
using namespace std;

int n, k;
int arr[100];
int res = 0;

void go(int idx, int sum) {
	if (sum == res) {
		res++;
		return;
	}

	if (idx >= n) return;

	go(idx + 1, sum + arr[idx]);
	go(idx + 1, sum);
}

int main() {
	

	cin >> n >> k;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	go(0,0);
	cout << res;
}