#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int dist[10][10];
int start;

int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength) {
	
	//gu출발지인 0번 도시로 돌아갈 수 있으면 재귀 종료
	if (path.size() == n && dist[path.back()][start] != 0)
		return currentLength + dist[path.back()][start];

	int ret = 2e9;

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue; //이미 방문한 도시인 경우
		int here = path.back();
		if (dist[here][next] == 0) continue; //이동이 불가능한 경우 
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

	//0번 도시에서 출발
	start = 0;
	path.push_back(0);
	visited[0] = true;
	cout << shortestPath(path, visited, 0);

	return 0;
}