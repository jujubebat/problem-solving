#include<iostream>
using namespace std;

int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int x, y;
	cin >> x >> y;

	int res = 0;
	for (int i = 1; i <= x; i++) {
		res += date[i-1];
	}
	res += y;

	if (res % 7 == 1) {
		printf("MON");
	}
	else if (res % 7 == 2) {
		printf("TUE");
	}
	else if (res % 7 == 3) {
		printf("WED");
	}
	else if (res % 7 == 4) {
		printf("THU");
	}
	else if (res % 7 == 5) {
		printf("FRI");
	}
	else if (res % 7 == 6) {
		printf("SAT");
	}
	else if (res % 7 == 0) {
		printf("SUN");
	}
}