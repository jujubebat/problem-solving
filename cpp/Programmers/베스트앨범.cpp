#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;

	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]] += plays[i];
	}

	priority_queue<pair<int, string>> pq; // 재생횟수, 장르

	for (auto it = m.begin(); it != m.end(); it++) {
		pq.push({ it->second, it->first });
	}

	while (!pq.empty()) {
		vector<pair<int, int>> tmpArr; // 재생횟수, 고유번호

		// 장르별로 노래를 뽑아낸다.
		for (int i = 0; i < genres.size(); i++) {
			if (genres[i] != pq.top().second) continue;
			tmpArr.push_back({ plays[i],i });
		}

		sort(tmpArr.begin(), tmpArr.end(), comp); // 재생횟수가 높은순, 고유번호가 작은순으로 정렬.

		// 장르별로 가장 많이 재생된 노래를 2개씩 뽑는다.
		if (tmpArr.size() == 1)
			answer.push_back(tmpArr[0].second);
		else {
			for (int i = 0; i < 2; i++) {
				answer.push_back(tmpArr[i].second);
			}
		}

		pq.pop();
	}

	return answer;
}