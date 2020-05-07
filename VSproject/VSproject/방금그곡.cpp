#include <string>
#include <vector>
#include <sstream>
#include<algorithm>
#include<iostream>

using namespace std;

typedef struct {
	int time, order;
}info;

bool comp(info a, info b) {
	if (a.time == b.time) //재생시간이 같으면
		return a.order < b.order; //입력순서가 빠른순으로
	else
		return a.time > b.time; //재생시간이 다르면, 재생 시간이 긴순으로
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	vector<string> log;
	vector<info> candi; // 재생시간, 입력순서

	string tmp = "";
	int idx = 0;

	while (m.find("#", idx) != string::npos)
	{
		idx = m.find("#", idx);
		char lower_alphabet = m[idx - 1] - 'A' + 'a';
		string alphabet;
		alphabet += lower_alphabet;
		m.replace(idx - 1, 2, alphabet);
	}

	cout << m << endl;
	for (int i = 0; i < musicinfos.size(); i++)
	{
		idx = 0;
		while (musicinfos[i].find("#", idx) != string::npos)
		{
			idx = musicinfos[i].find("#", idx);
			char lower_alphabet = musicinfos[i][idx - 1] - 'A' + 'a';
			string alphabet;
			alphabet += lower_alphabet;
			musicinfos[i].replace(idx - 1, 2, alphabet);
		}
		cout << musicinfos[i] << endl;
	}

	for (int i = 0; i < musicinfos.size(); i++) {

		for (int j = 0; j < musicinfos[i].size(); j++) {
			if (musicinfos[i][j] == ',') musicinfos[i][j] = ' ';
		}

		istringstream iss(musicinfos[i]);
		string st, et, title, note;

		iss >> st; //시작시간
		iss >> et; //끝나는시간
		iss >> title; //제목
		iss >> note; //악보

		log.push_back(title);

		int diff = ((et[0] - '0') * 10 + (et[1] - '0')) * 60 + ((et[3] - '0') * 10 + (et[4] - '0')) - ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + ((st[3] - '0') * 10 + (st[4] - '0'));

		string musicLog = "";
		idx = 0;
		while (diff--) {
			musicLog += note[idx++];
			if (idx == note.size())
				idx = 0;
		}

		for (int k = 0; k < musicLog.size(); k++) {
			if (k + m.size() > musicLog.size()) break;

			bool flag = true;
			idx = 0;

			for (int j = k; j < k + m.size(); j++) {
				if (m[idx++] != musicLog[j]) {
					flag = false;
				}
			}

			if (flag) {
				candi.push_back({ diff,i });
			}
		}
	}

	if (candi.size() == 0) return "(None)";

	sort(candi.begin(), candi.end(), comp);
	return log[candi[0].order];
}

