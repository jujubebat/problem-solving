#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> target;
vector<int> first;

int main() {
	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	bool flag = prev_permutation(arr.begin(), arr.end());

	if (flag) {
		for (int x : arr)
			printf("%d ", x);
	}
	else {
		printf("-1");
	}
	
	return 0;
}