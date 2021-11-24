#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { //01234
			printf(" ");
		}
		for (int j = 0; j < 2 * n -(i*2+1); j++){//97531
			printf("*");
		}
		puts("");
	}

	for (int i = 0; i < n-1; i++) {//0123
		for (int j = 0; j < n-2-i; j++) { //3210
			printf(" ");
		}
		for (int j = 0; j < (i+2)*2-1; j++) {//3579
			printf("*");
		}
		puts("");
	}
}