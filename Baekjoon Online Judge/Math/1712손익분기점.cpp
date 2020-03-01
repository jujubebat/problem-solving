#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c - b <= 0)
		printf("-1");
	else
		printf("%d", a/(c-b)+1);
	return 0;
}