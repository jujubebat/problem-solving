#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std; 

vector<long long> arr;

void dfs(string num) {
	
	if (num.size() > 0) {
		arr.push_back(stoll(num));
	}

	for (int i = 0; i <= 9; i++) {
		if (num.size() == 0|| num.back() - '0' > i) {
			dfs(num + (char)('0' + i));
		}
	}

}

int main() {
	dfs("");
	
	int size = arr.size();
	sort(arr.begin(), arr.end());

	int n;
	cin >> n;

	if (n > size)
		cout << -1;
	else
		cout << arr[n-1];
	
	return 0;
}