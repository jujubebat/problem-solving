#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int g, x;
		cin >> g >> x;
		arr[x] = g;
	}

	int cnt = 0;
	int len = k * 2 + 1;

	// ���� ������ �� �츮 ũ�⺸�� ũ�ٸ�, ��� �츮�� �ִ� �������� �ִ밪�̴�. 
	if (len > 1000000) {
		for (int i = 0; i <= 1000000; i++) {
			cnt += arr[i];
		}
		cout << cnt << endl;
		return 0;
	}

	// ����Ʈ�� �¿�� k��ŭ ������ �絿�̿� ������ �� �ִ�.
	// �̸� k*2+1 ������ �������� �����ߴ�. 
	// ù ������ ���� ����Ѵ�.
	for (int i = 0; i < len; i++) {
		cnt += arr[i];
	}

	int ret = cnt;

	// ��� k*2+1 ������ ������ ���� �������� ����ϰ�, �ִ� ���� �����Ѵ�. 
	for (int i = len; i <= 1000000; i++) {
		cnt -= arr[i - len];
		cnt += arr[i];
		ret = max(ret, cnt);
	}

	cout << ret;
	return 0;
}