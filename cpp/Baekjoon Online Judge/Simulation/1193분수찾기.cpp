#include<iostream>
using namespace std;

int  main() {
	int num = 0;
	int cnt = 1;
	int n;

	cin >> n;

	while (1) {
		cnt++;
		int i = 1;
		while (i<cnt) {
			num++;
			if (num == n) {
				if (cnt % 2 == 0)
					printf("%d/%d", cnt - i, i);
				else
					printf("%d/%d", i, cnt - i);
				return 0;
			}
			i++;
		}
	}
}