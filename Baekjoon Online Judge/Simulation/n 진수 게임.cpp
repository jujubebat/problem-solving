#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string convert(int num, int n) { // num을 n진법으로 바꾼 문자열 리턴.
	
	string ret = "";

	while (num > 0) {
		if (num%n < 10)
			ret += (char)(num%n + '0'); //number[num%n]; //+ ret;
		else
			ret += (char)(num%n - 10 + 'A');
		num /= n; 
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string numList = "";
	
	for (int i = 0; i < t*m; i++) {
		numList += convert(i, n); // 숫자 i를 n진수로 바꿔서 더해준다. 
	}
	
	for (int i = 0, cnt = 0; i < numList.size(); i++) {
		
		cnt++;

		if (cnt == p) { // p번째 숫자일 경우 결과 벡터에 추가.
			answer += numList[i];
		}

		if (cnt == m) { // m번쨰 숫자일경우 카운트를 초기화 한다.
			cnt = 0;
		}

		if (answer.size() >= t) { // 결과가 t개 이상이면 중단.
			break;
		}
	}

	return answer;
}