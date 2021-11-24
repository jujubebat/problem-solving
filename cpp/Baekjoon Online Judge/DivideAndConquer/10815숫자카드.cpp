#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int card[500000];
int mCard[500000];

bool search(int num) {
	int start = 0, end = n - 1;
	int mid = (start+end) / 2;

	//printf("%d %d %d \n", start, end, mid);

	while (start <= end) {
		mid = (start + end) / 2;

		//printf("%d %d %d \n", start, end, mid);
		if (num == card[mid])
			return true;
		else if (num < card[mid]) {
			end = mid - 1;
		}
		else if (num > card[mid]) {
			start = mid + 1;
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
		if (search(mCard[i]))
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}


