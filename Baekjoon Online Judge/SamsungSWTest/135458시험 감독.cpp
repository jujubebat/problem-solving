#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	vector<int> room;
	int b, c;

	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		room.push_back(num);
	}
	cin >> b >> c;

	long long res = 0;
	for (int i = 0; i < n; i++) {
		room[i] -= b;
		res++;
		if (room[i] <= 0) continue;
		if (room[i] / c == 0)
			res++;
		else if (room[i] / c > 0) {
			res += room[i] / c;
			if (room[i] % c != 0) res++;
		}
	}
	cout << res;
	return 0;
}