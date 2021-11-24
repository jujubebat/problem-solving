//ȥ�� ������ Ǯ�� ����
//queue�� �Ἥ �ذ��Ϸ��� ��� ����� but priority queue�� ����ؾ� ����
//�Է� ���� ������(�ε���, �߿䵵)�� ť�� ����
//�߿䵵�� �켱����ť�� ����
//ť���� �����͸� �ϳ��� ������, �켱����ť(max��)�� ����Ͽ� �߿䵵�� �ִ밪���� Ȯ��
//�߿䵵�� �ִ밪�̶��, �ε��� ���� M�� ��ġ�ϴ��� Ȯ���ϰ� ��ġ�ϸ� Ƚ���� ����ϰ� ����

#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

typedef struct {
	int idx, ipt; //�ε���, �߿䵵
}print;

int T, N, M; // M:Ÿ�ٹ��� ��ȣ

void function() {
	queue<print> q;
	priority_queue<int> pq;
	int num;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;
		q.push({ i, num }); //�ε����� �߿䵵�� q�� �ִ´�
		pq.push(num); //pq���� �߿䵵�� �ִ´�. 
	}

	while (1) {
		int idx = q.front().idx, ipt = q.front().ipt;
		q.pop();
		if (ipt == pq.top()) { //���� ť�� �Ӹ����� �̴� ���Ұ� ť������ �ִ밪�̶��,
			pq.pop();
			cnt++;
			if (idx == M) {
				break;
			}
		}
		else { //���� ť�� �Ӹ����� ���� ���Ұ� ť������ �ִ밪�� �ƴ϶��,
			q.push({ idx,ipt }); //�� ���Ҹ� ������ �ٽ� �־��ش�. 
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