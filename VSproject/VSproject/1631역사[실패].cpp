#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> o[401];
vector<int> r[401];

int n, k;
bool checkOrigin[401];
bool checkReverse[401];

bool flagOrigin = false;
bool flagReverse = false;

void dfsOrigin(int num, int target) {
	if (target == num) {
		flagOrigin = true;
		return;
	}

	checkOrigin[num] = true;

	for (int i = 0; i < o[num].size(); i++) {
		if (!checkOrigin[o[num][i]]) {
			dfsOrigin(o[num][i], target);
		}
	}
}

void dfsReverse(int num, int target) {
	if (target == num) {
		flagReverse = true;
		return;
	}
	
	checkReverse[num] = true;

	for (int i = 0; i < r[num].size(); i++) {
		if (!checkReverse[r[num][i]]) {
			dfsReverse(r[num][i], target);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;

		o[u].push_back(v);
		r[v].push_back(u);
	}

	int s;
	cin >> s;
	
	for (int i = 0; i < s; i++) {
		memset(checkOrigin, 0, sizeof(checkOrigin));
		memset(checkReverse, 0, sizeof(checkReverse));

		flagOrigin = false;
		flagReverse = false;

		int u, v;
		cin >> u >> v;

		dfsOrigin(u, v);
		dfsReverse(u, v);

		if (flagOrigin == flagReverse)
			cout << 0 << endl;
		else if (flagOrigin && !flagReverse)
			cout << -1 << endl;
		else if (!flagOrigin && flagReverse)
			cout << 1 << endl;
	
	}

	return 0;
}