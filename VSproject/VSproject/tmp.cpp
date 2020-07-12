#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	
	answer.push_back(0);
	answer.push_back(0);

	unordered_set<string> s;
	unordered_map<string, int> m;

	int kind;

	for (string tmp : gems) {
		s.insert(tmp);
	}

	kind = s.size();
	int start = 0, end = 0;
	int minValue = 0x7fffffff;

	while (1) {
		if (m.size() >= kind) {
			m[gems[start]]--;
			if (m[gems[start]] == 0)
				m.erase(gems[start]);
			start++;
		}
		else if (end >= gems.size())
			break;
		else {
			m[gems[end]]++;
			end++;
		}

		if (m.size() == kind) {
			if (end - start < minValue) {
				minValue = end - start;
				answer[0] = start + 1;
				answer[1] = end;
			}
		}
	}

	return answer;
}