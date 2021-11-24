#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> adj[10001]; // <����, ����ġ>
int n, d, c;

void dijkstra(int src, vector<int>& dist) { // ���ͽ�Ʈ�� �˰���.

	priority_queue<pair<int, int>> pq; // <����ġ, ����>

	dist[src] = 0; // ������ �ִܰŸ� 0���� �ʱ�ȭ.
	pq.push({ 0, src }); // pq�� �ִ´�.

	while (!pq.empty()) {
		int cost = -pq.top().first; // ������� ���� �ִܰŸ�(minHeap �̹Ƿ� '-' �� �ٿ���).
		int here = pq.top().second; // ����.
		pq.pop();

		if (dist[here] < cost) continue; // �̹� �� ª�� �ִܰŸ��� ����������, ��ŵ.

		for (int i = 0; i < adj[here].size(); i++) { // ���� ���� �˻�.
			int next = adj[here][i].first; // ������ �湮�� ����.
			int nextCost = cost + adj[here][i].second; // ������ �湮�� ���������� �Ÿ�.

			if (dist[next] > nextCost) { // ������ �湮�� ���������� �Ÿ��� �ִܰŸ����,
				dist[next] = nextCost; // �ִ� �Ÿ� ����.
				pq.push({ -nextCost, next }); // pq�� �־��ش�.
			}
		}
	}
}

int main() {
	int t;
	cin >> t; // �׽�Ʈ ���̽� �Է�

	while (t--) {

		for (int i = 0; i <= n; i++) { // ���� ����Ʈ �׷��� �ʱ�ȭ.
			adj[i].clear();
		}

		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ a,s }); // b ��ǻ�Ͱ� �����Ǹ�, s���� a ��ǻ�� ����.
		}

		vector<int> dist(10001, 0x7fffffff); // �ִ� �Ÿ� �迭 �ʱ�ȭ.
		dijkstra(c, dist); // ������ : ���� ��ŷ ���� ��ǻ�� c.

		int cnt = 0, time = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] < 0x7fffffff) { // ������ ��ǻ���� ���.
				cnt++; // �� ����.
				// ������ ��ǻ�Ͱ� �����Ǳ���� �ɸ� �ð� = �ִ� �Ÿ��� ���� ū ��.
				time = max(time, dist[i]); 
			}
		}

		cout << cnt << " " << time << endl; // ��� ���.
	}

	return 0;
}