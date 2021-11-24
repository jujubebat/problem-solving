#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> badList;
vector<int> v;
int n, m;
int res;
bool check[201][201];

void combination(int cnt) {

	if (v.size() == 3) {
		if (check[v[0]][v[1]] || check[v[1]][v[0]]) return;
		if (check[v[0]][v[2]] || check[v[2]][v[0]]) return;
		if (check[v[1]][v[2]] || check[v[2]][v[1]]) return;
		res++;
		return;
	}

	for (int i = cnt; i <= n; i++) {
		v.push_back(i);
		combination(i + 1);
		v.pop_back();
	}

}

int main() {

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		check[a][b] = check[b][a] = true;
	}

	combination(1);
	cout << res;

	return 0;
}