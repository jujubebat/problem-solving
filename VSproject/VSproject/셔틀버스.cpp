#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	int answer;
	priority_queue<int> timeTable;

	for (string time : timetable) {
		int h, m;

		sscanf(time.c_str(), "%d:%d", &h, &m);

		if ((h * 60 + m) == 23 * 60 + 59) continue;
		timeTable.push(-1 * (h * 60 + m)); // 분 단위로 계산, min heap
	}

	int time = 9 * 60;

	while (n > 0) {
		int cnt = 0;

		if (time == 9 * 60 || (time - 9 * 60) % t == 0) { // t분 간격으로
			int recentRideTime;

			while (1) {
				if (!timeTable.empty() && -timeTable.top() <= time) {
					recentRideTime = -timeTable.top(); // 가장 최근 탑승 시간 저장.
					timeTable.pop(); // 크루를 태운다. (== 힙에서 빼준다.)
					cnt++;
				}

				if (timeTable.empty() || cnt == m
					|| (!timeTable.empty() && -timeTable.top() > time)) {
					if (cnt == m) { // m명을 태웠을경우
						answer = recentRideTime - 1;
					}
					else {
						answer = time;
					}
					break;
				}
			}
			n--; // 셔틀 운행 횟수 감소.
		}
		time++; // 시간 증가 
	}

	string strAnswer = "";

	int hour = answer / 60;

	if (hour < 10)
		strAnswer += "0" + to_string(hour) + ":";
	else
		strAnswer += to_string(hour) + ":";

	int min = answer % 60;

	if (min < 10)
		strAnswer += "0" + to_string(min);
	else
		strAnswer += to_string(min);

	return strAnswer;
}





/*
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	int answer;
	priority_queue<int> timeTable;

	for (string time : timetable) {
		int h, m;

		sscanf(time.c_str(), "%d:%d", &h, &m);

		if ((h * 60 + m) == 1439) continue;
		timeTable.push(-1 * (h * 60 + m)); // 분 단위로 계산, min heap
	}

	int time = 540;

	while (n > 0) {
		int cnt = 0;

		if (time == 540 || (time - 540) % t == 0) { // t분 간격으로

			// 크루 도착 시간 <= 버스 도착 시간, 현재 탑승 인원이 m명 미만일때,
			// 버스에 크루를 태운다.

			int recentRideTime;

			while (1) {

				// 크루들을 태운다.
				if (!timeTable.empty() && -timeTable.top() <= time) {
					recentRideTime = -timeTable.top(); // 가장 최근 탑승 시간 저장.
					//cout << "recentRideTime : " << recentRideTime << endl;
					timeTable.pop(); // 크루를 태운다. (== 힙에서 빼준다.)
					cnt++;
					//cout << "cnt : " << cnt << endl;
				}

				// 태울 크루가 없거나, m명을 태웠거나,
				if (timeTable.empty() || cnt == m
					|| (!timeTable.empty() && -timeTable.top() > time)) {
					if (cnt == m) { // m명을 태웠을경우
						answer = recentRideTime - 1;
					}
					else {
						answer = time;
					}
					break;
				}
			}

			n--; // 셔틀 운행 횟수 감소.
		}
		time++; // 시간 증가
	}

	cout << answer << endl;
	string strAnswer = "";

	if (answer / 60 <= 9) {
		strAnswer += '0';
		strAnswer += answer / 60 + '0'; // +answer / 60 + '0';
	}
	else {
		strAnswer += answer/60/10 + '0';
		strAnswer += answer / 60 % 10 + '0';

	}

	answer %= 60;
	strAnswer += ':';

	if (answer <= 9) {
		strAnswer += '0';
		strAnswer += answer + '0';
	}
	else {
		strAnswer += answer / 10 + '0';
		strAnswer += answer % 10 + '0';
	}

	return strAnswer;
}




*/