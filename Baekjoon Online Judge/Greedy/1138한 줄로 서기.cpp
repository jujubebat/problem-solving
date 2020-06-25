#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	vector<pair<int, int>> arr;

	cin >> n;

	for (int height = 1; height <= n; height++) {
		int leftPersonNum;
		cin >> leftPersonNum;
		arr.push_back({ leftPersonNum, height }); // 왼쪽사람수, 키
	}

	sort(arr.begin(), arr.end());

	vector<pair<int, int>> ret;

	for (int i = 0; i < arr.size(); i++) {

		if (ret.size() == 0) {
			ret.push_back(arr[i]);
			arr.erase(arr.begin() + i);
			i--;
		}
		else {
			int leftPersonNum = arr[i].first;
			int height = arr[i].second;
			int cnt = 0;
			int insertIdx;

			for (int j = 0; j < ret.size(); j++) {
				if (ret[j].second > height)
					cnt++;

				if (cnt == leftPersonNum) {
					insertIdx = j;
				}

			}
			ret.insert(ret.begin() + insertIdx + 1, arr[i]);
			arr.erase(arr.begin() + i);
			i--;
		}
	}
	for (auto tmp : ret)
		cout << tmp.second << " ";

	return 0;
}
