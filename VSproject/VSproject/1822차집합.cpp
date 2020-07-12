#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> base;
	set<int> s;
	int a, b;

	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;
		if (s.count(num))
			s.erase(num);
	}

	if (s.size() == 0)
		cout << 0 << endl;
	else {
		cout << s.size() << endl;
		for (auto it = s.begin(); it != s.end(); it++) {
			cout << *it << " ";
		}
	}

	return 0;
}