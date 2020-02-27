#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> arr;
	int n;
	cin >> n;
	
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	
}