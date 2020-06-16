#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int start, end;
}logTime;

vector<logTime> timeList;

void convert(string log) {

	string a = "", b = "";
	int start = 0, end = 0;
	int cnt = 0;

	for (int i = 0; i < log.size(); i++) {
		if (log[i] == ' ') {
			cnt++;
			continue;
		}
		//if (log[i] == '.') continue;
		if (log[i] == 's') continue;


		if (cnt == 1) {
			a += log[i];
		}
		else if (cnt == 2) {
			b += log[i];
		}
	}

	cout << "B : " << stof(b) << endl;

	cout << "ab출력" << endl;
	cout << a << " " << b << endl;
	/*
	start = ((a[0] - '0') * 10 + (a[1] - '0') * 1)*3600000
		+ ((a[3] - '0') * 10 + (a[4] - '0') * 1) * 60000;

	start += stoi(a.substr(6, 5));
	end = start + stoi(b);*/

	end = ((a[0] - '0') * 10 + (a[1] - '0') * 1) * 3600000
		+ ((a[3] - '0') * 10 + (a[4] - '0') * 1) * 60000;

	string tmp = a.substr(6, 6);
	string after_tmp = "";
	for (int i = 0; i < tmp.size(); i++) {

		if (tmp[i] == '.') continue;
		after_tmp += tmp[i];
	}



	end += stoi(after_tmp);

	cout << "stoi(after_tmp)" << stoi(after_tmp) << endl;



	cout << "(int)(stof(b) * 1000) : " << (int)(stof(b) * 1000) << endl;
	start = end - (int)(stof(b) * 1000) + 1;

	cout << "start : " << start << " " << "end : " << end << endl;
	timeList.push_back({ start, end });

}
/*
23 59 59 999 ~23 59 59 999

86399999 + 1000 = 86400999*/

int count(int s, int e) { // s부터 e까지의 구간
	//cout << "count" << endl;
	//cout << s << " " << e << endl;
	int ret = 0;

	for (logTime n : timeList) {

		if (s <= n.start && n.start <= e)
			ret++;
		else if (s <= n.end && n.end <= e)
			ret++;
		else if (s > n.start && e < n.end)
			ret++;
	}



	//cout<<"ret : " << ret << endl;
	return ret;
}



/*

3603983 ~ 3604983
3604983 ~ 3605983



*/

/*
12345 ~ 13345

12345~13345*/

int solution(vector<string> lines) {
	int answer = 0;

	for (int i = 0; i < lines.size(); i++) {
		convert(lines[i]);
	}

	int firstLogTime = timeList[0].start; // 첫 시작 타임 (밀리초 기준)

	while (firstLogTime <= timeList[timeList.size() - 1].end) {
	//	cout << firstLogTime << " " << firstLogTime + 1000 << endl;
		answer = max(answer, count(firstLogTime, firstLogTime + 1000));
		firstLogTime++;
	}

	return answer;
}

//3598005~3599005
//3599005~3609005