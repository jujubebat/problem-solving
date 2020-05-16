/*M 블루레이 수
최소 블루레이 크기를 구해야함.
블루레이 최대 크기 10억 
1,000,000,000
블루레이 길이 범위?*/

#include<iostream>
#include<queue>
using namespace std;
int n, m;
int resson[100000];

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> resson[i];
	}

	int low = 0, high = 1000000000;

	while (low + 1 < high) {
		int mid = (low + high) / 2;
		int blueLayCnt = 1;
		int num = 0;

		for (int i = 0; i < n; i++) {
			if (resson[i] > mid) {
				blueLayCnt = m + 1;
				break;
			}
			if (num + resson[i] <= mid) {
				num += resson[i];
			}
			else {
				blueLayCnt++;
				num = resson[i];
			}
		}

		if (blueLayCnt <= m) {
			high = mid;
		}
		else if (blueLayCnt > m) {
			low = mid;
		}
	}
	
	cout << high << endl;
	
	return 0;
}