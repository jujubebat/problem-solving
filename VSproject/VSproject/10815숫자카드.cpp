#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int card[500000];
int mCard[500000];

bool binarySearch(int num) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (num == card[mid])
			return true;
		else if (num < card[mid]) {
			right = mid - 1;
		}
		else if (num > card[mid]) {
			left = mid + 1;
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card, card + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> mCard[i];
	}
	
	for (int i = 0; i < m; i++) {
		if (binarySearch(mCard[i]))
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}


