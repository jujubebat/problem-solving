#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int dist[10][10];
int start;

int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength) {
	
	//gu������� 0�� ���÷� ���ư� �� ������ ��� ����
	if (path.size() == n && dist[path.back()][start] != 0)
		return currentLength + dist[path.back()][start];

	int ret = 2e9;

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue; //�̹� �湮�� ������ ���
		int here = path.back();
		if (dist[here][next] == 0) continue; //�̵��� �Ұ����� ��� 
		path.push_back(next);
		visited[next] = true;
		int candi = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, candi);
		visited[next] = false;
		path.pop_back();
	}
	return ret;

}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}

	vector<int> path;
	vector<bool> visited(n,false);

	//0�� ���ÿ��� ���
	start = 0;
	path.push_back(0);
	visited[0] = true;
	cout << shortestPath(path, visited, 0);

	return 0;
}