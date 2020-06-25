#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef struct {
	int num, cnt, idx;
}dummy;

bool comp(dummy a, dummy b) {
	
	if (a.cnt == b.cnt) {
		return a.idx < b.idx;
	}
	else
		return a.cnt > b.cnt;
}

int main() {
	int n, c;
	int arr[1000];
	vector<dummy> ret;
	map<int, int> m;
	map<int, int> indexArr;

	cin >> n >> c;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]]++;
		if (indexArr.count(arr[i]) == 0)
			indexArr[arr[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		ret.push_back({arr[i], m[arr[i]],indexArr[arr[i]]});
	}

	sort(ret.begin(), ret.end(), comp);

	for (auto x : ret)
		cout << x.num << " ";

	return 0;
}