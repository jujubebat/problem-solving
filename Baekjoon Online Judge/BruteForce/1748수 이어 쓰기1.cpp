#include<iostream>

using namespace std;

int digit(int n){
	int cnt = 0;
	while (n!=0){
		n /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int n;
	int res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		res += digit(i);
	}
	printf("%d", res);
}