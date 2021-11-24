#include<iostream>
using namespace std;

int main() {
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++) { //0 1 2 3 
		for (int j = 0; j < i; j++) {//01234
			printf(" ");
		}

		for (int j = 0; j < (n - i) * 2 - 1; j++) {//97531
			printf("*");
		}
		puts("");
	}

	return 0;
}


