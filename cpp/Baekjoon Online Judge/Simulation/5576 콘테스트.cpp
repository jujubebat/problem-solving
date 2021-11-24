#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> w, k;

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		w.push_back(num);
	}

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		k.push_back(num);
	}

	sort(w.begin(), w.end(), greater<int>());
	sort(k.begin(), k.end(), greater<int>());
	cout << accumulate(w.begin(), w.begin() + 3, 0) << " " << accumulate(k.begin(), k.begin() + 3, 0);

	return 0;
}
