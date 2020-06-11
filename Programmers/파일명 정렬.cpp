#include <string>
#include <vector>
#include<algorithm>
using namespace std;

typedef struct {
	string name;
	string head;
	int number;
}fileData;

bool comp(fileData a, fileData b) {
	if (a.head == b.head) {
		return a.number < b.number;
	}
	else
		return a.head < b.head;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<fileData> fileDatas;

	for (int i = 0; i < files.size(); i++) {
		string head="", number = "";
		int idx;

		for (int j = 0; j < files[i].size(); j++) {

			if (isdigit(files[i][j])) {
				idx = j;
				break;
			}
			
			head += tolower(files[i][j]);
		}

		for (int j = idx; j < files[i].size(); j++) {

			if (!isdigit(files[i][j]) || number.size() >= 5) {
				break;
			}

			number += files[i][j];
		}
		fileDatas.push_back({ files[i], head, stoi(number) });
	}
	
	stable_sort(fileDatas.begin(), fileDatas.end(), comp);

	for (int i = 0; i < fileDatas.size(); i++)
		answer.push_back(fileDatas[i].name);

	return answer;
}
