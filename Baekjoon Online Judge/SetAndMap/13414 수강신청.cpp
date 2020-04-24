#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else
		return a.size() < b.size();
}

int main() {
	int n;

	cin >> n;

	vector<string> v;
	set<string> s;

	while (n--) {
		string str;
		cin >> str;

		if (s.count(str) == 0)
			v.push_back(str);
		
		s.insert(str);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}