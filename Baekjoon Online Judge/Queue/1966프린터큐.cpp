//혼자 힘으로 풀지 못함
//queue만 써서 해결하려고 계속 고민함 but priority queue를 사용해야 했음
//입력 받은 데이터(인덱스, 중요도)를 큐에 넣음
//중요도는 우선순위큐에 넣음
//큐에서 데이터를 하나씩 꺼내고, 우선순위큐(max힙)을 사용하여 중요도가 최대값인지 확인
//중요도가 최대값이라면, 인덱스 값이 M와 일치하는지 확인하고 일치하면 횟수를 출력하고 종료

#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

typedef struct {
	int idx, ipt; //인덱스, 중요도
}print;

int T, N, M; // M:타겟문서 번호

void function() {
	queue<print> q;
	priority_queue<int> pq;
	int num;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;
		q.push({ i, num }); //인덱스와 중요도를 q에 넣는다
		pq.push(num); //pq에는 중요도를 넣는다. 
	}

	while (1) {
		int idx = q.front().idx, ipt = q.front().ipt;
		q.pop();
		if (ipt == pq.top()) { //현재 큐의 머리에서 뽑는 원소가 큐에서의 최대값이라면,
			pq.pop();
			cnt++;
			if (idx == M) {
				break;
			}
		}
		else { //현재 큐의 머리에서 뽑은 원소가 큐에서의 최대값이 아니라면,
			q.push({ idx,ipt }); //그 원소를 꼬리에 다시 넣어준다. 
		}
	}
	cout << cnt << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		function();
	}
}