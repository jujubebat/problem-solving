#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	map<string, string> userMap;
	vector<vector<string>> log;

	for (int i = 0; i < record.size(); i++) {
		vector<string> elements;
		string tmp = "";

		for (int j = 0; j <= record[i].size(); j++) {
			if (record[i][j] == ' ' || j == record[i].size()) {
				elements.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += record[i][j];
			}
		}

		if(elements.size() >=3)
			userMap[elements[1]] = elements[2];

		log.push_back(elements);
	}

	vector<string> ret;

	for (int i = 0; i < log.size(); i++) {
		if (log[i][0] == "Enter") {
			ret.push_back(userMap[log[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (log[i][0] == "Leave") {
			ret.push_back(userMap[log[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}

	return ret;
}

/*

#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<vector<string>> log(record.size(), vector<string>(3));
	map<string, string> userMap;

	for (int i = 0; i < record.size(); i++) {
		istringstream iss(record[i]);

		iss >> log[i][0];
		iss >> log[i][1];
		iss >> log[i][2];

		if (log[i][0] == "Enter" || log[i][0] == "Change") {
			userMap[log[i][1]] = log[i][2];
		}

	}

	for (int i = 0; i < log.size(); i++) {
		if (log[i][0] == "Enter") {
			answer.push_back(userMap[log[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (log[i][0] == "Leave") {
			answer.push_back(userMap[log[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}

	return answer;
}

*/