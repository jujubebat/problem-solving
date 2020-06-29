#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;



typedef struct {
	int num, gold, silver, bronze;
}nation;

bool comp(nation a, nation b) {
	if (a.gold == b.gold) {
		if (a.silver == b.silver) {
			return a.bronze > b.bronze;
		}
		else
			return a.silver > b.silver;
	}
	else
		return a.gold > b.gold;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<nation> arr;
	nation target;

	for (int i = 0; i < n; i++) {
		int num, gold, silver, bronze;
		cin >> num >> gold >> silver >> bronze;
		nation tmp = { num, gold, silver, bronze };
		if (num == k) {
			target = tmp;
		}
		else {
			arr.push_back(tmp);
		}
	}

	int ret = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (target.gold == arr[i].gold
			&& target.silver == arr[i].silver
			&& target.bronze == arr[i].bronze)
			continue;


		if (comp(arr[i], target ))
			ret++;
	}

	cout << ret + 1;

	return 0;
}