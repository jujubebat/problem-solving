#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second > b.second;
}

int main() {

	map<string, int> m;
	int n;

	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		m[str]++;
	}

	vector<pair<string, int>> arr;

	for (auto tmp : m)
		arr.push_back({ tmp.first, tmp.second });

	sort(arr.begin(), arr.end(), comp);

	cout << arr[0].first;

	return 0;
}