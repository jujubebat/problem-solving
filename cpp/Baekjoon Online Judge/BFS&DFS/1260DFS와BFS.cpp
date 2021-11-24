/*
BFS(�ʺ� �켱 Ž��)
1.���� �湮���� ������ ������ ��� ������ Queue�� �ִ´�.(Queue�� ���� ������ �湮ó��)
2.Queue ��� �ִ� ������ ����.
3.1~2�� �ݺ��Ѵ�.

<������ ����ؾ��Ұ�>

*BFS�� ��ͷ� �����ϴ� ���� �ƴϴ�.  

*�湮ó��
-ť�� ������ �ִ´ٴ°��� �湮�ߴٴ� �ǹ�
-ť���� ������ ���ٴ� ���� �湮�� ������ ���� ������ Ȯ�� �ϱ� ����
-ť�� ������! �湮ó���� �������.

*Queue ����
-bfs�� ������ Queue�� ����ִ� ���¿��� �Ѵ�.
*/
/*
DFS(���� �켱 Ž��)
1.���� �湮���� ������ ���������� �˻��Ѵ�.
2.�湮���� ���� ������ �߰��ϸ�, �湮�Ѵ�.
3.1~2�� �ݺ��Ѵ�. 

<������ ����ؾ��� ��>

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
			if (!visited[y]) {//���� �湮���� ���� ���� �������� ť�� �ִ´�.
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
		adj[s].push_back(e); //������ �׷����̹Ƿ� ���� ����.
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