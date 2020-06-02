/*
데이터 삽입


우선순위 큐에 저장된 최대값과 최소값 출력. 
큐가 비었다면, Empty 출력
*/
// 1 1 1

// 삽입할때 map, max heap, min heap에 데이터 저장
// 우선순위 가장 높은 데이터 삭제 max heap에서 데이터 삭제 map 갱신
// 우선순위 가장 낮은 데이터 삭제 min heap에서 데이터 삭제 map 갱신

#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main() {
	
	int t;

	cin >> t;

	while (t--) {
		int k;

		map<int, int> m; // 데이터, 개수 
		priority_queue<int> maxHeap;
		priority_queue<int> minHeap;

		cin >> k;
		for (int i = 0; i < k; i++) {
			char op; int num;
			cin >> op >> num;

			if (op == 'I') {
				m[num]++;
				maxHeap.push(num);
				minHeap.push(-num);
			}
			else if (op == 'D') {
				if (num == 1 && !maxHeap.empty()) {
					//cout << "fuck1" << endl;
					while (!maxHeap.empty() && m[maxHeap.top()] <= 0) {
						maxHeap.pop();
					}
					//cout << "fuck2" << endl;

					if (!maxHeap.empty()) {
						m[maxHeap.top()]--;
						maxHeap.pop();
					}
					//cout << "fuck3" << endl;

				}
				else if (num == -1 && !minHeap.empty()) {
					while (!minHeap.empty() && m[-minHeap.top()] <= 0) {
						minHeap.pop();
					}
					if (!minHeap.empty()) {
						m[-minHeap.top()]--;
						minHeap.pop();
					}
					
				}
			}
		}

		while (!maxHeap.empty() && m[maxHeap.top()] <= 0) {
			maxHeap.pop();
		}

		while (!minHeap.empty() && m[-minHeap.top()] <= 0) {
			minHeap.pop();
		}

		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << maxHeap.top() << " " << -minHeap.top();
		}

	}

	return 0;
}