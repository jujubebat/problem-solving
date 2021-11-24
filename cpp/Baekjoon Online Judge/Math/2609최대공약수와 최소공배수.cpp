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

GCD : �ִ� �����
LCM : �ּ� �����

��Ŭ���� ȣ����
GCD(a,b) = GCD(a%b, r) //��ͷ� Ǯ���.
���� b=0�̸�, GCD(a,b) = a �̴�.

�ּ� ����� : a*b/GCD(a,b)
*/