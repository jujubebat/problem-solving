#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	long long ret = 0;

	sort(numbers.begin(), numbers.end());

	do {
		string candi = "";
		for (int num : numbers) {
			candi += to_string(num);
		}
		ret = max(ret, stoll(candi));
	} while (next_permutation(numbers.begin(), numbers.end()));

	return to_string(ret);
}