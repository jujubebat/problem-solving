#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int num; 
		cin >> num;
		arr.push_back(num * (i + 1));
	}
	
	int sum = 0;
	cout << arr[0] << " ";

	for (int i = 1; i < n; i++) {
		cout << arr[i] - arr[i - 1] << " ";
	}

	return 0;
}