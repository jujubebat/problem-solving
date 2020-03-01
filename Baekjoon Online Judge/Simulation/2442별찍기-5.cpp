#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;//5
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) {//4,3,2,1,0
			printf(" ");
		}
		for (int j = 0; j < 2*i+1; j++) {//1,3,5,7,9
			printf("*");
		}
		puts("");
	}
}