/*#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int arr[30000];
	int n, d, k, c;

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) { // �ʹ� ���� �Է�
		cin >> arr[i];
	}

	deque<pair<int, int>> window; // �ε���, �ʹ� ����
	map<int, int> m; // ���� : �ʹ� ����, ����
	int ret = -1;

	for (int i = 0; i < n+k; i++) {

		int idx = i;
		if (idx >= n) idx -= n;

		if (!window.empty() && window.front().first <= i - k ) {
			m[window.front().second]--; // �������� �ʹ� ���ش�.
			if (m[window.front().second] <= 0)
				m.erase(window.front().second);
			window.pop_front(); // �����쿡�� �ʹ��� ���ش�.
		}

		window.push_back({ idx, arr[idx] });
		m[arr[idx]]++;

		if (window.size() == k) {
			int num = (int)m.size();
			if (m.count(c) == 0) num++;
			ret = max(ret, num);
		}
	}

	cout << ret;
	return 0;
	
}*/

#include<iostream>
#include<algorithm>
using namespace std;

int table[30001];
int check[3001];

int main() {
	int n, d, k, c;

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}

	int size = 0;
	int cnt = 0;

	for (int i = 0; i < k; i++) { // ù k ������ ����Ѵ�. 
		if (check[table[i]]++ == 0) // ó�� ���ԵǴ� �ʹ��̶��, ī��Ʈ.
			cnt++;
	}

	int ret = cnt;

	for (int i = k; i < n + k; i++) { // n+k ������ k������ �����̵� �����츦 �δ�. 

		//�����̵� �����츦 �̴� �κ�.
		if (--check[table[i - k]] == 0) cnt--; // �� �ʹ��� ���ش�. check�� 0�̸�, ���� ī��Ʈ -1
		if (check[table[i%n]]++ == 0) cnt++; // �� �ʹ��� ���Ѵ�. check�� 0�̸�, ���� ī��Ʈ +1

		if (check[c] == 0) // ������ ����Ͽ� ������ ������ �����Ѵ�. 
			ret = max(ret, cnt + 1);
		else
			ret = max(ret, cnt);
	}

	cout << ret;
	return 0;
}