#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[20001];
int colorArr[20001];
int v, e;

bool isBipartite() {
	for (int i = 1; i <= v; i++) {
		for (int x : adj[i]) {
			if (colorArr[i] == colorArr[x])
				return false;
		}
	}
	return true;
}

void coloring(int n, int color) {//색칠 dfs, color 1 은 빨강 2은 검정
	colorArr[n] = color;

	int nextColor;
	if (color == 1) nextColor = 2;
	else nextColor = 1;

	for (int x : adj[n]) {
		if (!colorArr[x]) {
			coloring(x, nextColor);
		}
	}
}

void solve() {
	for (int i = 1; i <= v; i++) {//색칠하고
		if (!colorArr[i])
			coloring(i,1);
	}

	if (isBipartite())//이분 그래프 검사
		printf("YES\n");
	else
		printf("NO\n");
}

int main() {
	int k;
	int a, b;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		fill(colorArr, colorArr + v+1, 0);//color 초기화
		for (int i = 1; i <= v; i++) { //adj 초기화
			adj[i].clear();
		}
		for (int j = 0; j < e; j++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		solve();
	}
}