#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;
int arr[100][100];
bool visited[100];
int n;

int bfs(int start, int dest) {
	queue<int> q;
	q.push(start);//����Ŭ�� ��츦 �����Ͽ�(0���� 0�� �湮 �ϴ� ���) �������� �湮ó������ �ʴ´�. 

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int b = 0; b < n; b++) {
			if (arr[a][b] == 1 && !visited[b]) {
				if (b == dest) return 1; //ť�� ��������..
				q.push(b);
				visited[b] = true;
			}
		}
	}
	return 0;
}

int dfs(int start, int dest) {//����Ŭ�� ��츦  �����Ͽ� ������ �湮ǥ�� x
	for (int i = 0; i < n; i++) {
		if (arr[start][i] == 1 && !visited[i]) {
			if (i == dest)
				return 1;
			else {
				visited[i] = true;
				if (dfs(i, dest) == 1)//��������� Ż��..
					return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(visited, false, sizeof(visited));
			//printf("%d ", bfs(i, j));
			printf("%d ",dfs(i, j));
		}
		puts("");
	}
}