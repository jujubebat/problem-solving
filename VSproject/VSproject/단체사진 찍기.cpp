#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<string> data) {
	vector<char> arr;
	int answer = 0;

	arr.push_back('A');
	arr.push_back('C');
	arr.push_back('F');
	arr.push_back('J');
	arr.push_back('M');
	arr.push_back('N');
	arr.push_back('R');
	arr.push_back('T');

	do {
		bool flag = true;

		for (int i = 0; i < arr.size(); i++) { // ¼­ÀÖ´Â ÇÁ·»Áî Å½»ö

			for (int j = 0; j < data.size(); j++) { // Á¶°Ç Å½»ö

				if (arr[i] == data[j][0]) {

					char friends = data[j][2];
					char condition = data[j][3];
					int dist = data[j][4] - '0';

					int k;
					for (k = i; ;k++) {
						if (arr[k] == friends) break;
					}

					int cnt = abs(k - i) - 1;

					if (condition == '=') {
						if (cnt != dist) {
							flag = false;
							break;
						}
					}
					else if (condition == '>') {
						if (cnt <= dist) {
							flag = false;
							break;
						}
					}
					else if (condition == '<') {
						if (cnt >= dist) {
							flag = false;
							break;
						}
					}
				}

			}

			if (!flag) break;
		}

		if (flag)
			answer++;

	} while (next_permutation(arr.begin(), arr.end()));


	return answer;
}