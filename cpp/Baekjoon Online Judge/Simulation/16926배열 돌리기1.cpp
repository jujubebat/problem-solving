#include<vector>
#include<queue>
using namespace std;

// ������ ����
int V;

// �׷����� ���� ����Ʈ (����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
vector<pair<int, int>> adj[100];

vector<int> dijkstra(int src) {
	vector<int> dist(V, 0x7fffffff); // �� ������ �ִ� ��θ� ��� dist �迭�� �ʱ⿡ �ִ밪���� �����Ѵ�. 
	dist[src] = 0;
	priority_queue<pair<int, int>> pq; // (�ش� ������ ���� ������� ���� �ִܰ��, ���� ��ȣ)
	pq.push({ 0, src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ�, ���ݲ��� ���� �����Ѵ�.
		if (dist[here] < cost) continue;

		//������ �������� ��� �˻��Ѵ�.
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first; // ���� ���� ��ȣ
			int nextDist = cost + adj[here][i].second; // �ش� ���� ���������� �Ÿ� 

			if (dist[there] > nextDist) { // ���� ������ ���� �ִ� ��ζ��,
				dist[there] = nextDist; // dist �迭�� ������Ʈ
				pq.push({ -nextDist, there }); // (�ش� ������ ���� ���ο� �ִܰ��, ���� ��ȣ)
			}
		}
	}

	return dist;
}