#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, k;
	vector<int> arr;

	cin >> n >> k;
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr.push_back(num);
	}
	nth_element(arr.begin(), arr.begin() + k -1, arr.end());
	printf("%d",arr[k-1]);
}