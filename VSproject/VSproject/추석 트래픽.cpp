#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 로그의 시작점(시간)과 끝점(시간)을 저장하는 구조체
typedef struct {
	int start, end; 
}logTime;

vector<logTime> logList;

int count(int start, int end) { 
	int ret = 0;

	for (logTime log : logList) {
		if ((start <= log.start && log.start <= end) // 로그 시작점이 1초 구간에 포함 되는지 검사.
			|| (start <= log.end && log.end <= end) // 로그 끝점이 1초 구간에 포함 되는지 검사.
			|| (start > log.start && end < log.end)) // 로그가 1초 구간 전체에 포함 되는지 검사.
			ret++;
	}

	return ret; // 1초구간에 포함된 로그 개수 반환.
}

int solution(vector<string> lines) {
	int answer = 0;

	for (int i = 0; i < lines.size(); i++) {
		int y, m, d, hh, mm;
		double ss, period;

		// sscanf를 사용하면 간단하게 문자열 파싱을 할 수 있다.
		sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%lf %lfs", &y, &m, &d, &hh, &mm, &ss, &period);

		// 시간을 ms 단위로 바꾼다.
		int end = (hh * 3600 * 1000) + (mm * 60 * 1000) + (int)(ss * 1000);
		int start = end - (int)(period * 1000) + 1; // 끝시간을 포함하기 때문에 +1 해준다. 

		// 로그의 시작점과 끝점을 vector에 넣어준다. 
		logList.push_back({ start, end });
	}

	for (int i = 0; i < logList.size(); i++) {
		// 로그의 시작점부터 1초 구간에 로그가 몇 개 포함되는지 검사.
		answer = max(answer, count(logList[i].start, logList[i].start + 999)); 
		// 로그의 끝점부터 1초구간에 로그개 몇 개 포함되는지 검사. 
		answer = max(answer, count(logList[i].end, logList[i].end + 999)); 
	}

	return answer;
}