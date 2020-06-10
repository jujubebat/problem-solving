#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
	int answer = 0;

	string chance[3];
	int cnt = 0;
	string tmp = "";

	for (int i = 0; i < dartResult.size(); i++) {
		tmp += dartResult[i];

		if (dartResult[i] == 'S'
			|| dartResult[i] == 'D'
			|| dartResult[i] == 'T') {
			if (i < dartResult.size() - 1 && (
				dartResult[i + 1] != '#'
				|| dartResult[i + 1] != '*')) {
				chance[cnt++] = tmp;
				tmp = "";
			}
		}
		else if (dartResult[i] == '#'
			|| dartResult[i] == '*') {
			chance[cnt++] = tmp;
			tmp = "";
		}
	}

	cout << chance[0] << endl;
	cout << chance[1] << endl;
	cout << chance[2] << endl;

	return answer;
}