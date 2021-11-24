// �� 10�� �����ִ��� 1, 

#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int floor; //���� ��ġ�� ��
	int cnt; //��ư�� ���� Ƚ��
}elevator;

int F, S, G, U, D;
int res = 0;
bool visited[1000001];

void bfs() {
	queue<elevator> q;
	visited[S] = true;
	q.push({ S,0 });
	while (!q.empty()){
		int floor = q.front().floor;
		int cnt = q.front().cnt;
		q.pop();
		if (floor == G) {
			res = cnt;
			return;
		}
		int upFloor = floor + U, downFloor = floor - D;
		if (!visited[upFloor] && upFloor <= F) {
			visited[upFloor] = true;
			q.push({ upFloor, cnt + 1 });
		}
		if (!visited[downFloor] && downFloor >= 1) {
			visited[downFloor] = true;
			q.push({ downFloor, cnt + 1 });
		}
	}
	res = -1;
	return;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	bfs();
	if(res == -1)
		printf("use the stairs");
	else
		printf("%d", res);
	return 0;
}