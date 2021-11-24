//DFS�� BFS�� �⺻ �������� Ǯ����
//BFS�� �ð��� �� �� ������.
//DFS�� BFS�� �������� �˰� ������ Ǯ �� �ִ� ��������.
//���� �ڵ带 ���� �ʰ� ������ ������.
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, m,res=0;
vector<int> network[101];
queue<int> q;
int visited[101];

void bfs(int n) {
	visited[n] = true;
	q.push(n);
	res++;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int y : network[x]) {
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
				res++;
			}
		}
	}
}

void dfs(int n) {
	visited[n] = true;
	res++;

	for (int x : network[n]) {
		if (!visited[x])
			dfs(x);
	}
}

int main() {
	int a, b;
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		network[a].push_back(b);
		network[b].push_back(a);
	}

	//bfs(1);
	dfs(1);
	cout << res-1;
}