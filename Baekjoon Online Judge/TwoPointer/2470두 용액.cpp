//투포인터로 풀어보기
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[100000];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int a, b, s, e;

	a = s = 0;
	b = e = n - 1;

	while (s < e) {
		if (abs(arr[s] + arr[e]) < abs(arr[a] + arr[b])) {
			a = s, b = e;
		}

		if (arr[s] + arr[e] < 0)
			s++;
		else 
			e--;
	}

	cout << arr[a] << ' ' << arr[b];

	return 0;
}

/*#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[100000];

bool comp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, comp);

	int res = 0x7fffffff;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		if (abs(arr[i] + arr[i + 1]) < res) {
			res = abs(arr[i] + arr[i + 1]);
			a = arr[i], b = arr[i + 1];
		}
	}

	if (a <= b) cout << a << " " << b;
	else cout << b << " " << a;
	return 0;
}*/