/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[2];

void nextNum(int &num) {
	if (num % 2 == 0)
		num /= 2;
	else if (num % 2 != 0)
		num = num / 2 + 1;
}

int main() {
	int n;

	cin >> n >> arr[0] >> arr[1];
	sort(arr, arr + 2);
	int a = arr[0], b = arr[1];

	int round = 1;
	while (a > 0 && b > 0) {
		if (abs(a - b) == 1 && a%2 != 0 && b %2 ==0) {
			cout << round;
			return 0;
		}

		nextNum(a);
		nextNum(b);

		round++;
		n /= 2;
	}

	cout << -1;
	return 0;
}*/

#include<iostream>

using namespace std;

int n, k, l;
int cc;

int main(void)
{
	scanf_s("%d %d %d", &n, &k, &l);

	while (k != l)
	{
		k = (k + 1) / 2;
		l = (l + 1) / 2;
		cout << k << l << endl;
		cc++;
	}

	printf("%d", cc);
	return 0;
}