#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main() {
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	if (next_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
	}
	else
		printf("-1");

	return 0;
}