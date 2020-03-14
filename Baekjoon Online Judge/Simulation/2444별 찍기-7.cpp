#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {//01234
		
		for (int a = 0; a < n-i-1; a++) {//43210
			printf(" ");
		}

		for (int b = 0; b < i*2+1; b++) {//13579
			printf("*");
		}
		puts("");
	}

	for (int i = 0; i < n-1; i++) {
		for (int a = 0; a < i+1; a++) {//1234
			printf(" ");
		}

		for (int b = 0; b < (n-1-i)*2-1; b++) {//7531
			printf("*");
		}
		puts("");
	}

	return 0;
}