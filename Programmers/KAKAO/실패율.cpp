#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<double, int>> failRate;
double noneClear[501];
double clear[501];

bool comp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < stages.size(); j++) {
			if (i == stages[j])
				noneClear[i]++;
			if (stages[j] >= i)
				clear[i]++;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (clear[i] == 0)
			failRate.push_back({ 0 , i });
		else
			failRate.push_back({ noneClear[i] / clear[i] , i });
	}

	sort(failRate.begin(), failRate.end(), comp);

	for (int i = 0; i < failRate.size(); i++) {
		answer.push_back(failRate[i].second);
	}
	
	return answer;
}