//고민 끝에 스스로 문제를 품, BFS의 기본 개념을 활용해서 품.
#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int pos;
	int level;
}position;

int n, k;
int res = 0;
queue<position> q;
bool visited[100001];

void bfs(int n) {
	q.push({n, 0});

	while (!q.empty()) {
		int curPos = q.front().pos;
		int curlevel = q.front().level;
		visited[curPos] = true;

		q.pop();

		if (curPos == k) {
			res = curlevel;
			return;
		}
		else {
			if (!visited[curPos + 1]) q.push({ curPos + 1, curlevel + 1 });
			if (curPos > 0 && !visited[curPos - 1]) q.push({ curPos - 1, curlevel + 1 });
			if (curPos * 2 <= 100000 &&!visited[curPos * 2]) q.push({ curPos * 2, curlevel + 1 });
		}
	}
}

int main() {
	cin >> n>> k;
	bfs(n);
	printf("%d", res);
}