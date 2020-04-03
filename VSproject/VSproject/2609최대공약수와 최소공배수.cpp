#include<iostream>

using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << GCD(a, b) << endl;
	cout << a * b / GCD(a, b) << endl;

	return 0;
}

/*

GCD : 최대 공약수
LCM : 최소 공배수

유클리드 호제법
GCD(a,b) = GCD(a%b, r) //재귀로 풀면됨.
만약 b=0이면, GCD(a,b) = a 이다.

최소 공배수 : a*b/GCD(a,b)
*/