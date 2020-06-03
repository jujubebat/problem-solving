#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<string> g_words;

int solve(string query) {

	//cout << query << endl;

	int cnt = 0;

	for (int i = 0; i < g_words.size(); i++) { // 모든 단어 순회.

		if (g_words[i].size() != query.size()) continue; // 길이가 다르면 스킵.
		
		//cout << words[i] << " " << query << endl;
		bool flag = true;

		for (int j = 0; j < g_words[i].size(); j++) {

			if (query[j] == '?') continue;  //와일드 카드일 경우 pass.
			
			//cout << words[i][j] << " " << query[j] << endl;
			if (g_words[i][j] != query[j]) flag = false;
		}

		if (flag) cnt++;

	}

	//cout << "cnt : " << cnt << endl;
	return cnt;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	g_words = words;

	for (int i = 0; i < queries.size(); i++) {
		answer.push_back(solve(queries[i]));
	}

	return answer;
}