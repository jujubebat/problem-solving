#include<iostream>

using namespace std;

int main() {
	int n, m, k;
	int res = 0;
	cin >> n >> m >> k;

	while(1){
		n -= 2, m -= 1; //여자-2, 남자-1
		if (n < 0 || m < 0)
			break;
		if (n + m < k) //현재 여자+남자 인원이 k명보다 작다면, 팀 그만 만들기
			break;
		res++; //팀수 증가
	}
	printf("%d", res);
}

/*
6 4 1

6 4 
4 3 1
2 2 2
0 1 3
-2 0
*/
