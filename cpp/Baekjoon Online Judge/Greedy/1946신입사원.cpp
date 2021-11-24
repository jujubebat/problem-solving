#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	pair<int,int> arr[100000];
	int t,n,res;
	cin >> t;

	while (t--) {
		cin >> n;
		res = n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr, arr + n);
		
		int res = 1;
		int temp = arr[0].second;
		for (int i = 1; i < n; i++) {
			if (temp > arr[i].second) {
				res++;
				temp = arr[i].second;

				if (temp == 1) break;
			}
		}
		printf("%d\n", res);
	}
}