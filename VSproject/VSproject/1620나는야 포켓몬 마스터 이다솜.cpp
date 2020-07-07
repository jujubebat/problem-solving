#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> map;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;

		map[str] = to_string(i);
		map[to_string(i)] = str;
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		cout << map[name] << '\n';
	}

	return 0;
}