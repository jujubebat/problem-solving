#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	vector<int> a, b;
	set<int> aSet, bSet;

	int aNum, bNum;
	cin >> aNum >> bNum;

	for (int i = 0; i < aNum; i++) {
		int num;
		cin >> num;
		a.push_back(num);
		aSet.insert(num);
	}


	for (int i = 0; i < bNum; i++) {
		int num;
		cin >> num;
		b.push_back(num);
		bSet.insert(num);
	}

	int ret = 0;

	for (int i = 0; i < aNum; i++) {
		if (bSet.count(a[i]) == 1) continue;
		ret++;
	}

	for (int i = 0; i < bNum; i++) {
		if (aSet.count(b[i]) == 1) continue;
		ret++;
	}

	cout << ret;
	return 0;
}