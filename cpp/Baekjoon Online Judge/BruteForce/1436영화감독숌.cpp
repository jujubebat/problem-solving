//혼자 힘으로 오래걸려 풀었음
//더 좋은 답안이 있어서 참고함
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string str;
	int res = 0;

	cin >> n;
	int cnt = 0;

	// 모범 답안 (%1000으로 3자리가 666인지 한번에 확인)
	for (long long i = 666; ; i++) {
		long long num = i;
		while (num >= 666)
		{
			if (num % 1000 == 666) {
				cnt++;
				if (cnt == n) {
					cout << i;
					return 0;
				}
				break;
			}
			num /= 10;
		}
	}
	

	//내가 짠 방법( %10으로 한자리씩 검사해서 연속으로 6인지 확인)
	/*
	for (int i = 666; ; i++) {
		int cnt = 0,num=i;

		while (num > 0) {
			if (num % 10 == 6)
				cnt++;
			else
				cnt = 0;

			if (cnt == 3) {
				res++;
				break;
			}
			num /= 10;
		}

		if (res == n) {
			printf("%d", i);
			break;
		}
	}*/
}