#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t; // 테스트 케이스 입력.

	while (t--) {

		int k;
		map<long long, int> m; // <숫자, 숫자의 개수> 
		priority_queue<long long> maxHeap;
		priority_queue<long long> minHeap;

		cin >> k; // 명령어 개수 입력.

		for (int i = 0; i < k; i++) { 
			char op; long long num;
			cin >> op >> num; // 명령어 입력.

			if (op == 'I') { // 이중 우선순위 큐에 숫자 삽입.
				m[num]++; // 동기화를 위해 map에 숫자 개수 기록.
				maxHeap.push(num);
				minHeap.push(-num);
			}
			else if (op == 'D') {
				if (num == 1) { 

					// 숫자의 개수가 0이란 뜻은 삭제된 데이터란 뜻으로 모두 삭제한다.
					while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
						maxHeap.pop();
					}

					if (!maxHeap.empty()) { 
						m[maxHeap.top()]--;  // 개수를 빼준다.
						if (m[maxHeap.top()] < 0) m[maxHeap.top()] = 0;
						maxHeap.pop(); // 최대값 삭제.
					}
				}
				else if (num == -1) { 

					while (!minHeap.empty() && m[-minHeap.top()] == 0) {
						minHeap.pop();
					}

					if (!minHeap.empty()) {
						m[-minHeap.top()]--; // 개수를 빼준다.
						if (m[-minHeap.top()] < 0) m[-minHeap.top()] = 0;
						minHeap.pop(); // 최소값 삭제.
					}
				}
			}
		}

		// 위와 마찬가지. 숫자의 개수가 0이란 뜻은 삭제된 데이터란 뜻으로 모두 삭제한다.
		while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
			maxHeap.pop();
		}

		while (!minHeap.empty() && m[-minHeap.top()] == 0) {
			minHeap.pop();
		}

		// 힙이 비어있을 경우.
		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY" << endl;
		}
		else { // 비어있지 않을 경우 결과 출력.
			cout << maxHeap.top() << " " << -minHeap.top() << endl;
		}
	}

	return 0;
}