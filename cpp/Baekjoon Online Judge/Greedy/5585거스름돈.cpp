#include<iostream>
using namespace std;

int main() {
	int n,tmp;
	int cnt = 0;

	cin >> n;
	tmp = 1000-n;
	while (tmp) {
		if (tmp >= 500)
		{
			cnt += tmp / 500;
			tmp %= 500;
		}
		else if (tmp >= 100)
		{
			cnt += tmp / 100;
			tmp %= 100;
		}
		else if (tmp >= 50) {
			cnt += tmp / 50;
			tmp %= 50;
		}
		else if (tmp >= 10) {
			cnt += tmp / 10;
			tmp %= 10;
		}
		else if(tmp >=5) {
			cnt += tmp / 5;
			tmp %= 5;
		}
		else {
			cnt += tmp;
			tmp = 0;
		}
	}

	printf("%d", cnt);
}