
/*
-dfs로 1~n-1개를 뽑는 조합을 구한다.
-각 조합을 구할때 마다, 두 각 지역구의 연결여부 검사(bfs or dfs)
-두 지역구간 인구차를 구한다.
-최소값을 기록한다.
*/

//전역변수명과 매개변수명 중복 사용
//지역변수명과 매개변수명 중복 사용
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n;

vector<int> adj[11];
int numOfPeople[11];
int res = 2e9;
bool visited[11];
int strd;

bool bfs(bool standard) { //각 지역구의 연결여부 검사
	queue<int> q;
	bool tmpVisited[11];
	copy(visited, visited + 11, tmpVisited);

	for (int i = 1; i <= n; i++) {
		if (tmpVisited[i] == standard) {
			tmpVisited[i] = !standard;
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x : adj[v]) {
			if (tmpVisited[x] == standard) {
				tmpVisited[x] = !standard;
				q.push(x);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (tmpVisited[i] == standard)
			return false;
	}
	return true;
}

//각 조합을 구할때 마다, 두 각 지역구의 연결여부 검사후(bfs) 두 지역구간 인구차를 구함
void findDiff() {
	if (!bfs(false) || !bfs(true)) {
		return;
	}

	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			a += numOfPeople[i];
		}
		else {
			b += numOfPeople[i];
		}
	}
	
	//printf("a %d b %d abs(a-b)%d\n", a, b, abs(a - b));

	int minValue = abs(a - b);
	if (minValue < res)
		res = minValue;
}

void dfs(int cnt, int size) {
	
	findDiff();
	if (size == strd) {
		return;
	}
	for (int i = cnt; i <= n; i++) {
		visited[i] = true;
		dfs(i + 1, size + 1);
		visited[i] = false;
	}
}

void solve() {
	for (int i = 1; i <= n/2; i++) {
		strd = i;
		dfs(1, 0);
	}
}

int main() {
	scanf("%d", &n);
	getchar();

	for (int i = 1; i <= n; i++) {
		scanf("%d", &numOfPeople[i]);
	}
	getchar();

	int numOfLocation = 0;
	for (int i = 1; i <= n; i++) {
		cin >> numOfLocation;
		for (int j = 0; j < numOfLocation; j++) {
			int v;
			cin >> v;
			adj[i].push_back(v);
		}
		getchar();
	}

	solve();

	if (res == 2e9)
		printf("-1");
	else
		printf("%d", res);
}