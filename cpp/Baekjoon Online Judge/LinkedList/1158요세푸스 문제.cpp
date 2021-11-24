#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> arr, res;
	int N, K, cur_idx = 0;

	scanf("%d %d", &N, &K);

	//printf("dfs");
	K -= 1;

	for (int i = 1; i <= N; i++)
		arr.push_back(i);

	int target;

	while (!arr.empty()) {
		target = cur_idx + K;

		if (target >= arr.size()) {
			target %= arr.size();
		}

		cur_idx = target;

		res.push_back(arr[target]);
		arr.erase(arr.begin() + target);
	}

	printf("<");
	for (int i = 0; i < res.size() - 1; i++)
		printf("%d, ", res[i]);
	printf("%d", res[res.size() - 1]);
	printf(">");

}