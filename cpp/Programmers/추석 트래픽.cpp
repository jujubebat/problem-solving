#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// �α��� ������(�ð�)�� ����(�ð�)�� �����ϴ� ����ü
typedef struct {
	int start, end; 
}logTime;

vector<logTime> logList;

int count(int start, int end) { 
	int ret = 0;

	for (logTime log : logList) {
		if ((start <= log.start && log.start <= end) // �α� �������� 1�� ������ ���� �Ǵ��� �˻�.
			|| (start <= log.end && log.end <= end) // �α� ������ 1�� ������ ���� �Ǵ��� �˻�.
			|| (start > log.start && end < log.end)) // �αװ� 1�� ���� ��ü�� ���� �Ǵ��� �˻�.
			ret++;
	}

	return ret; // 1�ʱ����� ���Ե� �α� ���� ��ȯ.
}

int solution(vector<string> lines) {
	int answer = 0;

	for (int i = 0; i < lines.size(); i++) {
		int y, m, d, hh, mm;
		double ss, period;

		// sscanf�� ����ϸ� �����ϰ� ���ڿ� �Ľ��� �� �� �ִ�.
		sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%lf %lfs", &y, &m, &d, &hh, &mm, &ss, &period);

		// �ð��� ms ������ �ٲ۴�.
		int end = (hh * 3600 * 1000) + (mm * 60 * 1000) + (int)(ss * 1000);
		int start = end - (int)(period * 1000) + 1; // ���ð��� �����ϱ� ������ +1 ���ش�. 

		// �α��� �������� ������ vector�� �־��ش�. 
		logList.push_back({ start, end });
	}

	for (int i = 0; i < logList.size(); i++) {
		// �α��� ���������� 1�� ������ �αװ� �� �� ���ԵǴ��� �˻�.
		answer = max(answer, count(logList[i].start, logList[i].start + 999)); 
		// �α��� �������� 1�ʱ����� �αװ� �� �� ���ԵǴ��� �˻�. 
		answer = max(answer, count(logList[i].end, logList[i].end + 999)); 
	}

	return answer;
}