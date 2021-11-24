/*
[20/08/27]

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int ret = 0;
	int n, b, w;
	string str;

	cin >> n >> b >> w;
	cin >> str;

	int start = 0, end = 0;
	int bCnt = 0, wCnt = 0;

	while (1) {
		if (bCnt <= b && wCnt >= w) {
			ret = max(ret, end - start);
			if (str[end] == 'B')
				bCnt++;
			else if (str[end] == 'W')
				wCnt++;
			end++;
		}
		else if (bCnt > b) {
			if (str[start] == 'B')
				bCnt--;
			else if (str[start] == 'W')
				wCnt--;
			start++;
		}
		else if (wCnt < w) {
			if (str[end] == 'B')
				bCnt++;
			else if (str[end] == 'W')
				wCnt++;
			end++;
		}
		if (end > n) break;
	}

	cout << ret;
	return 0;
}
*/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[300000];

int main() {
	int n, b, w;
	cin >> n >> b >> w;

	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;

		if (ch == 'W') arr[i] = 1;
	}

	int ret = 0;
	int low = 0, high = 0;
	int white = 0, black = 0;

	while (high <= n) {
		//cout << "조약돌" << white << " " << black << endl;
		if (white >= w && black <= b) { // 조건을 만족한다면,
			//cout << "조약돌" << white << " " << black << endl;
			//cout << low << " " << high << endl;
			ret = max(ret, high - low); // 구간 길이 갱신하고,
			if (arr[high++]) // 더 긴 구간이 있는지 확인해본다.
				white++;
			else
				black++;
		}
		else if (white < w) { // 흰 조약돌이 모자라면,
			if (arr[high++]) // 구간을 늘려본다.
				white++;
			else
				black++;
		}
		else if (black > b) { // 검은 조약돌이 많으면,
			if (arr[low++]) // 구간을 줄여본다.
				white--;
			else
				black--;
		}
	}

	cout << ret;

	return 0;
}

// 투포인터로 구간 살펴보면서, 조건에 맞는 구간길이 갱신