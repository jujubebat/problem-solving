#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(string s) {

	int len = s.size();
	int answer = len;

	for (int i = 1; i <= len; i++) { //i는 자를 길이 단위이다.

		string result = "";
		string temp = s.substr(0, i);
		int cnt = 1;

		for (int j = i; j <= len; j += i) { //i만큼 잘라서 문자열을 압축한다. 
			if (temp == s.substr(j, i)) {
				cnt++;
			}
			else {
				if (cnt == 1)
					result += temp;
				else
					result += to_string(cnt) + temp;
				temp = s.substr(j, i);
				cnt = 1;
			}
		}

		if (len / i != 0) //문자열이 i로 나누어 떨어지지 않을 경우 
			result += s.substr((len / i)*i);

		answer = min(answer, (int)result.size());
	}

	return answer;
}