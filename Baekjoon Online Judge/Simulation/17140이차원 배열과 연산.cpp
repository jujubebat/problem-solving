#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, k;
int map[100][100];
int rlen = 3, clen = 3;

void R() {
	int maxLen;
	for (int i = 0; i < rlen; i++) { //행
		int count[101] = { 0 };
		vector<pair<int, int>> element;

		for (int j = 0; j < clen; j++) { //숫자의 개수를 센다. 
			//if (j >= 100) break; //크기가 100개가 넘어가면 나머지는 버린다.
			count[map[i][j]]++;
			map[i][j] = 0;
		}

		for (int k = 1; k <= 100; k++) { // 빈도수, 숫자 순서로 pair 벡터를 만들어준다.
			if (count[k])
				element.push_back({ count[k], k });
		}

		sort(element.begin(), element.end()); //정렬한다. 

		int idx = 0;
		for (int k = 0; k < element.size(); k++) {
			map[i][idx++] = element[k].second; //숫자를 넣어준다.
			//if (idx >= 100) break;
			map[i][idx++] = element[k].first; //빈도수를 넣어준다.
			//if (idx >= 100) break;
		}
		maxLen = max(maxLen, idx);
	}
	clen = max(clen, maxLen);
}

void C() {
	int maxLen;
	for (int j = 0; j < clen; j++) { //행
		int count[101] = { 0 };
		vector<pair<int, int>> element;

		for (int i = 0; i < clen; i++) { //숫자의 개수를 센다. 
			//if (i >= 100) break; //크기가 100개가 넘어가면 나머지는 버린다.
			count[map[i][j]]++;
			map[i][j] = 0;
		}

		for (int k = 1; k <= 100; k++) { // 빈도수, 숫자 순서로 pair 벡터를 만들어준다.
			if (count[k])
				element.push_back({ count[k], k });
		}

		sort(element.begin(), element.end()); //정렬한다. 

		int idx = 0;
		for (int k = 0; k < element.size(); k++) {
			map[idx++][j] = element[k].second; //숫자를 넣어준다.
			//if (idx >= 100) break;
			map[idx++][j] = element[k].first; //빈도수를 넣어준다.
			//if (idx >= 100) break;
		}
		maxLen = max(maxLen, idx);
	}
	rlen = max(rlen, maxLen);
}

void solve() {
	int res = 0;

	while (1) {
		if (map[r][c] == k) {
			cout << res;
			return;
		}

		if (res > 100) {
			cout << -1;
			return;
		}

		if (rlen >= clen)
			R();
		else
			C();
		res++;
	}
}

int main() {
	cin >> r >> c >> k;
	r -= 1, c -= 1;

	for (int i = 0; i < rlen; i++) {
		for (int j = 0; j < clen; j++) {
			cin >> map[i][j];
		}
	}

	solve();
	return 0;
}