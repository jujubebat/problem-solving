#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n;
	map<char, int> m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		
		cin >> str;

		m[str[0]]++;
	} 
	
	string ret = "";

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second >= 5)
			ret.push_back(it->first);
	}

	if (ret.size() == 0) {
		cout << "PREDAJA";
	}

	sort(ret.begin(), ret.end());

	cout << ret;

	return 0;
}