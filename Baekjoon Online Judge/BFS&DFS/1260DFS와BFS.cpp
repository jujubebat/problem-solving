/*
BFS(너비 우선 탐색)
1.현재 방문중인 정점에 인접한 모든 정점을 Queue에 넣는다.(Queue에 들어가는 정점은 방문처리)
2.Queue 들어 있는 정점을 뺀다.
3.1~2를 반복한다.

<구현시 고려해야할것>

*BFS는 재귀로 구현하는 것이 아니다.  

*방문처리
-큐에 정점을 넣는다는것은 방문했다는 의미
-큐에서 정점을 뺀다는 것은 방문한 정점의 인접 정점을 확인 하기 위함
-큐에 넣을때! 방문처리를 해줘야함.

*Queue 관리
-bfs가 끝난후 Queue는 비어있는 상태여야 한다.
*/
/*
DFS(깊이 우선 탐색)
1.현재 방문중인 정점의 인접정점을 검사한다.
2.방문하지 않은 정점을 발견하면, 방문한다.
3.1~2를 반복한다. 

<구현시 고려해야할 것>

*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAX = 1001;
vector<int> adj[MAX];
queue<int> q;
bool visited[MAX];

void DFS(int v) {
	visited[v] = true;
	printf("%d ", v);

	for (int x : adj[v]) {
		if (!visited[x])
			DFS(x);
	}
}

void BFS(int v) {
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);

		for (int y : adj[x]) {
			if (!visited[y]) {//아직 방문하지 않은 인접 정점들을 큐에 넣는다.
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	int n, m, v;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int s, e;

		scanf("%d %d", &s, &e);
		adj[s].push_back(e); //무방향 그래프이므로 양쪽 연결.
		adj[e].push_back(s);
	}
	
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(v);
	puts("");
	memset(visited, 0, sizeof(visited));
	BFS(v);
}