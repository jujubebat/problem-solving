#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int s=2, e=7;
	int i = 1, j = 2, ret = 1;
	while (1)
	{
		if (n == 1) {
			printf("1");
			return 0;
		}

		ret++;
		if (n >= s && n <= e) {
			printf("%d", ret);
			return 0;
		}
		s += 6 * i, e += 6 * j;
		i++, j++;
	}
	return 0;
}
/*2~7 까지 1 /6(k)
8~19 까지 2 /12(k)
20~37 까지 3 / 18(k)
38~58 까지 4 / 21(k)*/