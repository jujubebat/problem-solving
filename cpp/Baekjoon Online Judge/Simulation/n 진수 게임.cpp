#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string convert(int num, int n) { // num�� n�������� �ٲ� ���ڿ� ����.
	
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
		numList += convert(i, n); // ���� i�� n������ �ٲ㼭 �����ش�. 
	}
	
	for (int i = 0, cnt = 0; i < numList.size(); i++) {
		
		cnt++;

		if (cnt == p) { // p��° ������ ��� ��� ���Ϳ� �߰�.
			answer += numList[i];
		}

		if (cnt == m) { // m���� �����ϰ�� ī��Ʈ�� �ʱ�ȭ �Ѵ�.
			cnt = 0;
		}

		if (answer.size() >= t) { // ����� t�� �̻��̸� �ߴ�.
			break;
		}
	}

	return answer;
}