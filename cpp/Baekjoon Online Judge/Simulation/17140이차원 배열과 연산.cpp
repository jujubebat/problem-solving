#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, k;
int map[100][100];
int rlen = 3, clen = 3;

void R() {
	int maxLen;
	for (int i = 0; i < rlen; i++) { //��
		int count[101] = { 0 };
		vector<pair<int, int>> element;

		for (int j = 0; j < clen; j++) { //������ ������ ����. 
			//if (j >= 100) break; //ũ�Ⱑ 100���� �Ѿ�� �������� ������.
			count[map[i][j]]++;
			map[i][j] = 0;
		}

		for (int k = 1; k <= 100; k++) { // �󵵼�, ���� ������ pair ���͸� ������ش�.
			if (count[k])
				element.push_back({ count[k], k });
		}

		sort(element.begin(), element.end()); //�����Ѵ�. 

		int idx = 0;
		for (int k = 0; k < element.size(); k++) {
			map[i][idx++] = element[k].second; //���ڸ� �־��ش�.
			//if (idx >= 100) break;
			map[i][idx++] = element[k].first; //�󵵼��� �־��ش�.
			//if (idx >= 100) break;
		}
		maxLen = max(maxLen, idx);
	}
	clen = max(clen, maxLen);
}

void C() {
	int maxLen;
	for (int j = 0; j < clen; j++) { //��
		int count[101] = { 0 };
		vector<pair<int, int>> element;

		for (int i = 0; i < clen; i++) { //������ ������ ����. 
			//if (i >= 100) break; //ũ�Ⱑ 100���� �Ѿ�� �������� ������.
			count[map[i][j]]++;
			map[i][j] = 0;
		}

		for (int k = 1; k <= 100; k++) { // �󵵼�, ���� ������ pair ���͸� ������ش�.
			if (count[k])
				element.push_back({ count[k], k });
		}

		sort(element.begin(), element.end()); //�����Ѵ�. 

		int idx = 0;
		for (int k = 0; k < element.size(); k++) {
			map[idx++][j] = element[k].second; //���ڸ� �־��ش�.
			//if (idx >= 100) break;
			map[idx++][j] = element[k].first; //�󵵼��� �־��ش�.
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