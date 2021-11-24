#include<iostream>
using namespace std;

int main() {
	long long d[100];
	
	d[0] = d[1] = d[2] = 1;
	for (int i = 3; i < 100; i++) {
		d[i] = d[i - 2] + d[i - 3];
	}

	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("%lld\n",d[n-1]);
	}
}