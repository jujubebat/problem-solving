#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	set<string> st;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		st.insert(s);
	}

	int ret = 0;

	for (int j = 0; j < m; j++) {
		string s;
		cin >> s;
		if (st.count(s))
			ret++;
	}

	cout << ret;

	return 0;
}