#include <string>
#include <vector>

using namespace std;

// "�빮��#" ������ ��ǥ�� "�ҹ���" ���·� �ٲ��ִ� �Լ�.
string convert(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '#') {
			ret.back() = tolower(ret.back());
		}
		else
			ret += str[i];
	}
	return ret;
}

string solution(string m, vector<string> musicinfos) {

	string answer = "";
	int answerTime = 0;

	string listen = convert(m); // �׿��� ���� ��θ� ��ȯ.

	for (int i = 0; i < musicinfos.size(); i++) { // ��۵� �� ������ �ϳ��� ��ȸ
		string st = "", et = "", title = "", note = "";

		// ','�� �������� �� ������ �Ľ��Ѵ�. 
		int check = 0;
		for (int j = 0; j < musicinfos[i].size(); j++) { 
			if (musicinfos[i][j] == ',') check++;
			if (musicinfos[i][j] != ',' && check == 0)
				st += musicinfos[i][j];
			else if (musicinfos[i][j] != ',' && check == 1)
				et += musicinfos[i][j];
			else if (musicinfos[i][j] != ',' && check == 2)
				title += musicinfos[i][j];
			else if (musicinfos[i][j] != ',' && check == 3)
				note += musicinfos[i][j];
		}

		// ����, ���� �ð��� �д����� ��ȯ�� ���� �� ���� ���� ����ð��� ���Ѵ�. 
		int start = ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + ((st[3] - '0') * 10 + (st[4] - '0'));
		int end = ((et[0] - '0') * 10 + (et[1] - '0')) * 60 + ((et[3] - '0') * 10 + (et[4] - '0'));
		int playTime = end - start;

		if (playTime < listen.size()) continue;

		note = convert(note); // �Ǻ� ��ȯ.
		string playNote = ""; // ����� �Ǻ� ����.

		// ����ð��� �Ǻ��� ���� ����� �Ǻ� ������ �����.
		for (int j = 0; j < playTime; j++) {
			if (j > note.size() - 1) { 
				playNote += note[j % note.size()];
			}
			else {
				playNote += note[j];
			}
		}

		// find �Լ��� ����� ����� �Ǻ��� �׿��� ���� ��ε� �ִ��� ã�´�. 
		if (playNote.find(listen) != string::npos) {

			if (answer.size() == 0) {
				answer = title;
				answerTime = playTime;
			}
			else { // ���ǿ� �´� ���� ������ ���������, ��� �ð��� �� ���� ������ �����̴�.
				if (playTime > answerTime) { 
					answer = title;
					answerTime = playTime;
				}
			}
		}
		// �߰���, �� ������ �տ������� ���� �����ϹǷ� ���� �Էµ� ���� ������ ��ȯ�ȴ�. 
	}

	if (answer.size() == 0) return "(None)"; // ��ġ�ϴ� ���� ���� ���.
	return answer;
}


