#include <string>
#include <vector>

using namespace std;

// "대문자#" 형태의 음표를 "소문자" 형태로 바꿔주는 함수.
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

	string listen = convert(m); // 네오가 들은 멜로리 변환.

	for (int i = 0; i < musicinfos.size(); i++) { // 방송된 곡 정보를 하나씩 조회
		string st = "", et = "", title = "", note = "";

		// ','을 기준으로 곡 정보를 파싱한다. 
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

		// 시작, 종료 시간을 분단위로 변환한 다음 그 차를 구해 재생시간을 구한다. 
		int start = ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + ((st[3] - '0') * 10 + (st[4] - '0'));
		int end = ((et[0] - '0') * 10 + (et[1] - '0')) * 60 + ((et[3] - '0') * 10 + (et[4] - '0'));
		int playTime = end - start;

		if (playTime < listen.size()) continue;

		note = convert(note); // 악보 변환.
		string playNote = ""; // 재생된 악보 변수.

		// 재생시간과 악보를 통해 재생된 악보 정보를 만든다.
		for (int j = 0; j < playTime; j++) {
			if (j > note.size() - 1) { 
				playNote += note[j % note.size()];
			}
			else {
				playNote += note[j];
			}
		}

		// find 함수를 사용해 재생된 악보에 네오가 들은 멜로디가 있는지 찾는다. 
		if (playNote.find(listen) != string::npos) {

			if (answer.size() == 0) {
				answer = title;
				answerTime = playTime;
			}
			else { // 조건에 맞는 음악 제목이 여러개라면, 재생 시간이 긴 음악 제목이 정답이다.
				if (playTime > answerTime) { 
					answer = title;
					answerTime = playTime;
				}
			}
		}
		// 추가로, 곡 정보를 앞에서부터 순차 접근하므로 먼저 입력된 음악 제목이 반환된다. 
	}

	if (answer.size() == 0) return "(None)"; // 일치하는 곡이 없을 경우.
	return answer;
}


