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
		timeTable.push(-1 * (h * 60 + m)); // �� ������ ���, min heap
	}

	int time = 9 * 60;

	while (n > 0) {
		int cnt = 0;

		if (time == 9 * 60 || (time - 9 * 60) % t == 0) { // t�� ��������
			int recentRideTime;

			while (1) {
				if (!timeTable.empty() && -timeTable.top() <= time) {
					recentRideTime = -timeTable.top(); // ���� �ֱ� ž�� �ð� ����.
					timeTable.pop(); // ũ�縦 �¿��. (== ������ ���ش�.)
					cnt++;
				}

				if (timeTable.empty() || cnt == m
					|| (!timeTable.empty() && -timeTable.top() > time)) {
					if (cnt == m) { // m���� �¿������
						answer = recentRideTime - 1;
					}
					else {
						answer = time;
					}
					break;
				}
			}
			n--; // ��Ʋ ���� Ƚ�� ����.
		}
		time++; // �ð� ���� 
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
		timeTable.push(-1 * (h * 60 + m)); // �� ������ ���, min heap
	}

	int time = 540;

	while (n > 0) {
		int cnt = 0;

		if (time == 540 || (time - 540) % t == 0) { // t�� ��������

			// ũ�� ���� �ð� <= ���� ���� �ð�, ���� ž�� �ο��� m�� �̸��϶�,
			// ������ ũ�縦 �¿��.

			int recentRideTime;

			while (1) {

				// ũ����� �¿��.
				if (!timeTable.empty() && -timeTable.top() <= time) {
					recentRideTime = -timeTable.top(); // ���� �ֱ� ž�� �ð� ����.
					//cout << "recentRideTime : " << recentRideTime << endl;
					timeTable.pop(); // ũ�縦 �¿��. (== ������ ���ش�.)
					cnt++;
					//cout << "cnt : " << cnt << endl;
				}

				// �¿� ũ�簡 ���ų�, m���� �¿��ų�,
				if (timeTable.empty() || cnt == m
					|| (!timeTable.empty() && -timeTable.top() > time)) {
					if (cnt == m) { // m���� �¿������
						answer = recentRideTime - 1;
					}
					else {
						answer = time;
					}
					break;
				}
			}

			n--; // ��Ʋ ���� Ƚ�� ����.
		}
		time++; // �ð� ����
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