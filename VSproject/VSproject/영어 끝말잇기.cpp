#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> s;
	s.insert(words[0]);

	for (int i = 1; i < words.size(); i++) {
		if ((words[i - 1].back() != words[i].front())
			|| (s.count(words[i]) == 1)) {

			int num = i % n + 1;
			int cnt = i / n + 1;

			answer.push_back(num);
			answer.push_back(cnt);

			break;
		}
		s.insert(words[i]);
	}

	if (answer.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}


	return answer;
}