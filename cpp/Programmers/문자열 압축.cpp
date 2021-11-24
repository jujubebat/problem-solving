#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(string s) {

	int len = s.size();
	int answer = len;

	for (int i = 1; i <= len; i++) { //i�� �ڸ� ���� �����̴�.

		string result = "";
		string temp = s.substr(0, i);
		int cnt = 1;

		for (int j = i; j <= len; j += i) { //i��ŭ �߶� ���ڿ��� �����Ѵ�. 
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

		if (len / i != 0) //���ڿ��� i�� ������ �������� ���� ��� 
			result += s.substr((len / i)*i);

		answer = min(answer, (int)result.size());
	}

	return answer;
}