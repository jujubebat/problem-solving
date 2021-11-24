#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	int n;
	cin >> n;

	long long s;
	cin >> s;

	vector<long long> a;

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		a[i] = abs(s - a[i]);
	}

	long long ret = a[0];

	for (int i = 1; i < n; i++) {
		ret = gcd(ret, a[i]);
	}

	cout << ret;
}