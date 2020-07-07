#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int maxVal = -1;
	string str;
	map<char, int> m;

	char ch;

	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] < 'a' || str[i] > 'z') continue;
			m[str[i]]++;
			maxVal = max(maxVal, m[str[i]]);
		}
	}

	map<char, int>::iterator it;

	string ret = "";

	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == maxVal)
			ret += it->first;
	}
	
	sort(ret.begin(), ret.end());
	cout << ret;
	return 0;
}

