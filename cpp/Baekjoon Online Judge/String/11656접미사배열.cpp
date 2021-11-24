#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> s;

int main() {
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		string tmp = "";
		for (int j = i; j < str.size(); j++) {
			tmp += str[j];
		}
		s.push_back(tmp);
	}

	sort(s.begin(), s.end());

	for (string x : s)
		cout << x << endl;

	return 0;
}