#include<iostream>
#include<vector> 
#include<cstring>
#include<cmath>
using namespace std;

bool arr[1001] = { true };

vector<int> ret;

int main() {

	memset(arr, true, sizeof(arr));
	int n, k;

	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		if (arr[i] == true)
			ret.push_back(i);

		for (int j = i+i; j <= n; j += i) {
			if (arr[j] == true)
				ret.push_back(j);
			arr[j] = false;
		}

	}
	cout << ret[k - 1];
	return 0;
}