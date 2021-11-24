#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	set<string> s;
	vector<string> ret;

	int n, m;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		s.insert(name);
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		if (s.count(name) == 1)
			ret.push_back(name);
	}

	sort(ret.begin(), ret.end());

	cout << ret.size() << endl;

	for (auto tmp : ret)
		cout << tmp << endl;

	return 0;
}