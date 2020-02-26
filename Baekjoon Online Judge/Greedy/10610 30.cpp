//30의 배수에 대한 규칙을 찾는다.
//첫째자리가 0이고 나머지 자리의 숫자합은 3의 배수다. 
//배열에다가 숫자 정보를 집어넣고, 큰수부터 출력한다.
//매단계 지금 당장 좋은 방법을 선택하는 그리디 알고리즘

#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int n, sum = 0;
	int arr[10] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		n = s[i] - '0';
		sum += n;
		arr[n]++;
	}

	if (arr[0] == 0 || sum % 3 != 0) {
		printf("-1\n");
		return 0;
	}


	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++)
			printf("%d", i);
	}

	printf("\n");
	return 0;
}