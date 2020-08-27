#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	map<int, int> m;

	string num = "";
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]))
			num += s[i];
		else {
			if (num.size() > 0) {
				m[stoi(num)]++;
				num = "";
			}
		}
	}

	vector<pair<int, int>> arr;

	for (auto tmp : m)
		arr.push_back({ tmp.second, tmp.first });

	sort(arr.begin(), arr.end(), greater<pair<int, int>>());

	for (auto tmp : arr)
		answer.push_back(tmp.second);

	return answer;
}