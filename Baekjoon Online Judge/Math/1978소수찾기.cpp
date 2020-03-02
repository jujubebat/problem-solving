#include<iostream>
using namespace std;

bool isPrime(int n) {
	if (n == 1)
		return false;

	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}

	return true;
}

int main() {
	int n,res = 0;
	int arr[100];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (isPrime(arr[i]))
			res++;
	}
	printf("%d", res);
}