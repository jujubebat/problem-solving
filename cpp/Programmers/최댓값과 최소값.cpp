#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> arr;
	string tmp = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			arr.push_back(stoi(tmp));
			tmp = "";
		}
		else if (i == s.size() - 1) {
			tmp += s[i];
			arr.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}

	sort(arr.begin(), arr.end());
	return to_string(arr.front()) + " " + to_string(arr.back());
}