#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string convert(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '#') {
			ret[ret.size() - 1] = tolower(ret[ret.size() - 1]);
		}
		else
			ret += str[i];
	}
	return ret;
}

//cout << listen << " " << playNote.substr(j, listen.size()) << endl;

bool comp(string listen, string playNote) {
	for (int j = 0; j <= playNote.size() - listen.size(); j++) {
		if (listen.compare(playNote.substr(j, listen.size())) == 0)
			return true;
	}
	return false;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int answerTime = 0;

	string listen = convert(m); // convert 문제 없음, m # 파싱

	cout << "listen : " << listen << endl;

	for (int i = 0; i < musicinfos.size(); i++) { // 음악들 for문돌리고
		string st, et, title, note;
		int cnt = 0;
		for (int j = 0; j < musicinfos[i].size(); j++) { // , 을 공백으로 바꿔준다.
			if (musicinfos[i][j] != ',' && cnt == 0)
				st += musicinfos[i][j];
			if (musicinfos[i][j] != ',' && cnt == 1)
				et += musicinfos[i][j];
			if (musicinfos[i][j] != ',' && cnt == 2)
				title += musicinfos[i][j];
			if (musicinfos[i][j] != ',' && cnt == 3)
				note += musicinfos[i][j];
			if (musicinfos[i][j] == ',')
				cnt++;
		}

		int start = ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + ((st[3] - '0') * 10 + (st[4] - '0'));
		int end = ((et[0] - '0') * 10 + (et[1] - '0')) * 60 + ((et[3] - '0') * 10 + (et[4] - '0'));

		if (end == 0) {
			end = 12 * 60;
		}

		int playTime = end - start;
		if (playTime < listen.size()) continue;

		note = convert(note); // note #으로 변환 주어진 음악악보
		string playNote = ""; // 실행된 음악 ( 시간고려)

		int size = note.size(); // 주어진 음악악보 크기

		for (int j = 0; j < playTime; j++) {
			if (j > size - 1) { // 주어진 음악악보 크기보다 인덱스가 크면
				playNote += note[j % size];
			}
			else {
				playNote += note[j];
			}
		}

		//if (playNote.find(listen) != string::npos) {
		
		if(comp(listen, playNote)){ // m파싱한값과, 시간고려한 음악악보를 비교
			cout << "playNote : " << playNote << endl;
			cout << "listen : " << listen << endl;
			cout << "playTime : " << playTime << endl;

			if (answer.size() == 0) {
				answer = title;
				answerTime = playTime;
			}
			else {
				if (playTime > answerTime) {
					answer = title;
					answerTime = playTime;
				}
			}
		}
		cout << endl;
	}

	if (answer.size() == 0)
		return "(None)";

	return answer;
}



