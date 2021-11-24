/*#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	int n, k, b;
	bool arr[100001] = { false };

	cin >> n >> k >> b;

	for (int i = 0; i < b; i++) { // ���峭 ��ȣ�� ������ bool �迭�� ���
		int num;
		cin >> num;
		arr[num] = true;
	}

	int low = 0, high = 100000; // 0���� �����ص�, ������ ������ �� �ִ�.
	int ret = 100000;

	while (low <= high) {
		int mid = (low + high) / 2; // ������ ��ȣ���� ���� 
		bool flag = false;
		deque<int> window;

		// ���� ����� �����̵� ������� ������ k���� ��ȣ���� ���ӵ��ִ��� Ȯ���Ѵ�. 
		for (int i = 1; i <= n; i++) {
			if (i > k && !window.empty() && window.front() <= i-k)
				window.pop_front();

			if (!arr[i])
				window.push_back(i);
   
			if (i >= k && k - window.size() <= mid) {
				flag = true;
			}
		}

		if (flag) { // mid������ ��ŭ ��ȣ���� ���� ������ K���� ��ȣ���� ���ӵ��ִٸ�,
			ret = min(ret, mid); // �ּ� ���� ������ ���Ѵ�.
			high = mid - 1; // ��ȣ���� �� ���� �����غ���. 
		}
		else { // mid������ ��ŭ ��ȣ���� ���� ������ K���� ��ȣ���� ���� ���� �ʴٸ�,
			low = mid + 1; // ��ȣ���� �� ���� �����غ���.
		}
	}

	cout << ret;

	return 0;
}*/


#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	int n, k, b;
	bool arr[100001] = { false };

	cin >> n >> k >> b;

	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;
		arr[num] = true;
	}

	int broken = 0;

	for (int i = 1; i <=k; i++) {
		if (arr[i])
			broken++;
	}

	int ret = broken;

	for (int i = k + 1; i <= n; i++) {
		if (arr[i])
			broken++;
		if (arr[i - k])
			broken--;

		ret = min(ret, broken);
	}

	cout << ret;
	return 0;
}

