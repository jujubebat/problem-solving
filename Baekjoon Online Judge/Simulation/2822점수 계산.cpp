#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> arr, ret;

	for (int i = 1; i <= 8; i++) {
		int score;
		cin >> score;
		arr.push_back({ score, i });
	}
	
	sort(arr.begin(), arr.end(), greater<pair<int, int>>());

	int totalScore = 0;
	for (int i = 0; i < 5; i++) {
		ret.push_back({ arr[i].second, arr[i].first });
		totalScore += arr[i].first;
	}

	sort(ret.begin(), ret.end());

	cout << totalScore << endl;

	for (auto tmp : ret) {
		cout << tmp.first << " ";
	}

	return 0;
}