#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int arr[1000000];
int x, n;
vector<int> v;
int ret = -1;


void find(int idx) {
	int low = 0, high = n;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		int size = arr[idx] + arr[mid];

		if (size >= x) {
			if (size == x && idx != mid) {
				if (abs(arr[idx] - arr[mid]) > ret) {
					ret = abs(arr[idx] - arr[mid]);
					v.clear();
					v.push_back(idx);
					v.push_back(mid);
				}
			}
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> x) {

		memset(arr, 0, sizeof(arr));
		v.clear();
		ret = -1;

		x *= 10000000;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		for (int i = 0; i < n; i++) {
			find(i);
		}

		if (v.empty())
			cout << "danger" << endl;
		else {
			sort(v.begin(), v.end());
			cout << "yes " << arr[v[0]] << " " << arr[v[1]] << endl;
		}
	}

	return 0;
}

// 1, 2, 9999998, 9999999
// ¹é¸¸ 6 * 1000000