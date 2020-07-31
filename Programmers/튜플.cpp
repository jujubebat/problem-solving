#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {

	vector<int> answer;

	vector<pair<int, vector<int>>> tuples;
	bool start = false;
	vector<int> element;
	int num = 0;

	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == ',' && s[i + 1] == '{')
			s.erase(s.begin() + i);
	}
	for (int i = 1; i < s.size() - 1; i++) {
		cout << s[i] << endl;
	}


	/*
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '{') continue;

		if (isdigit(s[i]))
			num = num * 10 + s[i]-'0';

		if (s[i] == ',' || s[i] == '}') {
			element.push_back(num);
			num = 0;
		}

		if (s[i] == '}') {
			tuples.push_back({ element.size(), element });
			element.clear();
		}
	}

	sort(tuples.begin(), tuples.end());

	bool check[100001] = { false };

	for (int i = 0; i < tuples.size(); i++) {
		for (int j = 0; j < tuples[i].second.size(); j++) {
			int num = tuples[i].second[j];
			if (!check[num]) {
				check[num] = true;
				answer.push_back(num);
			}
		}
	}*/

	return answer;
} #include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {

	vector<int> answer;

	vector<pair<int, vector<int>>> tuples;
	bool start = false;
	vector<int> element;
	int num = 0;

	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == ',' && s[i + 1] == '{')
			s.erase(s.begin() + i);
	}
	for (int i = 1; i < s.size() - 1; i++) {
		cout << s[i] << endl;
	}


	/*
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '{') continue;

		if (isdigit(s[i]))
			num = num * 10 + s[i]-'0';

		if (s[i] == ',' || s[i] == '}') {
			element.push_back(num);
			num = 0;
		}

		if (s[i] == '}') {
			tuples.push_back({ element.size(), element });
			element.clear();
		}
	}

	sort(tuples.begin(), tuples.end());

	bool check[100001] = { false };

	for (int i = 0; i < tuples.size(); i++) {
		for (int j = 0; j < tuples[i].second.size(); j++) {
			int num = tuples[i].second[j];
			if (!check[num]) {
				check[num] = true;
				answer.push_back(num);
			}
		}
	}*/

	return answer;
}