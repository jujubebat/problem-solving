#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<string> arr;
	unordered_set<string> s;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		arr.push_back(str);
		s.insert(str);
	}

	for (int i = 0; i < arr.size(); i++) {
		reverse(arr[i].begin(), arr[i].end());
		if (s.count(arr[i])==1) {
			cout << arr[i].size() << " "<< arr[i][arr[i].size()/2] <<endl;
			return 0;
		}
	}

	return 0;
}