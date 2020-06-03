#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

string s;
vector<char> v;
int len;
bool visited[10];
set<vector<char>> st;
int ret = 0;

void permutation() {

	if (v.size() == len) {

		for (char x : v)
			cout << x << " ";
		cout << endl;

		/*//cout << st.count(v) << endl;
		if (st.count(v) == 0) {
			st.insert(v);
			//ret++;
		}*/

		return;
	}

	for (int i = 0; i < len; i++) {
		if (!visited[i]) {
			if (v.size() > 0 && v[v.size() - 1] == s[i]) continue;

			visited[i] = true;
			v.push_back(s[i]);
			permutation();
			v.pop_back();
			visited[i] = false;

		}
	}

}

int main() {

	cin >> s;
	//len = s.size();

	cout << s;

	//permutation();
	//cout << ret;

	return 0;
}