#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
	vector<int> tmp = arr;

	while (1) {
		int maxValue = 0;
		set<int> s;

		for (int i = 0; i < arr.size(); i++) {
			s.insert(arr[i]);
			maxValue = max(maxValue, arr[i]);
		}

		if (s.size() == 1) {
			return arr[0];
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] < maxValue)
				arr[i] += tmp[i];
		}
	}

	return -1;
}

