#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool time[2000000];

int main() {
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int cycle;
		cin >> cycle;
		for (int j = cycle; j <= c; j += cycle){
			time[j] = true;
		}
	}

	cout << count(time, time + c + 1, true);
	return 0;
}

