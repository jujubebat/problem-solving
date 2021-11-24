#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> strs;

	for (int num : numbers) {
		strs.push_back(to_string(num));
	}

	sort(strs.begin(), strs.end(), comp);

	for (auto str : strs) {
		answer += str;
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}