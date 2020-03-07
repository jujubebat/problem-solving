#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}

	do {
		for (int x : arr) {
			printf("%d ", x);
		}
		puts("");
	} while (next_permutation(arr.begin(), arr.end()));
	return 0;
}