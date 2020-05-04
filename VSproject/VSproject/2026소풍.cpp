#include<iostream>
#include<vector>
using namespace std;

int k, n, f;
int map[900][900];
vector<int> v;
bool flag = true;

bool isPossible(int num) {
	
	for (int f : v) {
		if (!map[f][num]) return false;
	}

	return true;
}

void search(int cnt) {
	if (!flag) return;

	if (v.size() == k) {
		for (int f : v)
			cout << f+1<< endl;
		flag = false;
		return;
	}

	for (int i = cnt; i < n; i++) {
		if (!isPossible(i)) continue;
		v.push_back(i);
		search(i + 1);
		v.pop_back();
	}
}

int main() {
	cin >> k >> n >> f;

	for (int i = 0; i < f; i++) {
		int a, b; 
		cin >> a >> b;
		a -= 1, b -= 1;
		map[a][b] = map[b][a] = true;
	}

	search(0);

	if (flag)
		cout << -1;

	return 0;
}