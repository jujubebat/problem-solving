#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
	int answer = 1;
	int size = s.size();
	int len = s.size();

	while (1) {
		for (int i = 0; i + len <= s.size(); i++) {
			bool flag = true;
			for (int j = 0; j < len / 2; j++) {
				if (s[i + j] != s[i + len - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) return len;
		}
		len--;
	}

	return answer;
}