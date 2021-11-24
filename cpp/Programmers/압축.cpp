#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> m;

	for (int i = 0; i <= 25; i++) {
		string tmp = "";
		tmp += 'A' + i;
		m[tmp] = i+1;
	}
	
	int index = 27;
	string input = "";
	
	for (int i = 0; i < msg.size(); i++) {
		
		input += msg[i];

		if (i < msg.size() - 1 && m.count(input+msg[i+1])) {
			continue;
		}

		string tmp = "";

		// 사전에서 현재 입력과 일치하는 가장 긴문자열을 찾는다.
		if (m.count(input)) { 
			answer.push_back(m[input]); // w에 해당하는 사전의 색인 번호를 출력.
			tmp = input;
			input = ""; // 입력에서 w를 제거한다. 
		}

		if (i < msg.size() - 1) {
			m[tmp + msg[i + 1]] = index++;
		}
		
	}

	return answer;
}