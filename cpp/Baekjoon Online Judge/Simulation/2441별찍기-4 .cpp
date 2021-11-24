#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--) {
		for (int j = i; j < n; j++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		puts("");
	}
	return 0;
}