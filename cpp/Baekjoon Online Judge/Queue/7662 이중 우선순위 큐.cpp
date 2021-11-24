#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t; // �׽�Ʈ ���̽� �Է�.

	while (t--) {

		int k;
		map<long long, int> m; // <����, ������ ����> 
		priority_queue<long long> maxHeap;
		priority_queue<long long> minHeap;

		cin >> k; // ��ɾ� ���� �Է�.

		for (int i = 0; i < k; i++) { 
			char op; long long num;
			cin >> op >> num; // ��ɾ� �Է�.

			if (op == 'I') { // ���� �켱���� ť�� ���� ����.
				m[num]++; // ����ȭ�� ���� map�� ���� ���� ���.
				maxHeap.push(num);
				minHeap.push(-num);
			}
			else if (op == 'D') {
				if (num == 1) { 

					// ������ ������ 0�̶� ���� ������ �����Ͷ� ������ ��� �����Ѵ�.
					while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
						maxHeap.pop();
					}

					if (!maxHeap.empty()) { 
						m[maxHeap.top()]--;  // ������ ���ش�.
						if (m[maxHeap.top()] < 0) m[maxHeap.top()] = 0;
						maxHeap.pop(); // �ִ밪 ����.
					}
				}
				else if (num == -1) { 

					while (!minHeap.empty() && m[-minHeap.top()] == 0) {
						minHeap.pop();
					}

					if (!minHeap.empty()) {
						m[-minHeap.top()]--; // ������ ���ش�.
						if (m[-minHeap.top()] < 0) m[-minHeap.top()] = 0;
						minHeap.pop(); // �ּҰ� ����.
					}
				}
			}
		}

		// ���� ��������. ������ ������ 0�̶� ���� ������ �����Ͷ� ������ ��� �����Ѵ�.
		while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
			maxHeap.pop();
		}

		while (!minHeap.empty() && m[-minHeap.top()] == 0) {
			minHeap.pop();
		}

		// ���� ������� ���.
		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY" << endl;
		}
		else { // ������� ���� ��� ��� ���.
			cout << maxHeap.top() << " " << -minHeap.top() << endl;
		}
	}

	return 0;
}