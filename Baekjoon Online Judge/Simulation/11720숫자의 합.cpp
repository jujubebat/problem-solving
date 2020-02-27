#include<iostream>
using namespace std;

int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%1d", &num);
		res += num;
	}
	printf("%d", res);
}