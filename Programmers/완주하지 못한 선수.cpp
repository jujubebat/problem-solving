#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> m;

	for (auto people : completion) {
		m[people]++;
	}

	for (auto people : participant) {
		if (m[people] > 0) {
			m[people]--;
		}
		else if (m[people] == 0) {
			return people;
		}
	}
}