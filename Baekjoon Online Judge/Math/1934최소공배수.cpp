
//GCD : Greatest Common Divisor
//LCM : Leat Common Multiple

/*
GCD(a,b) = GCD(b, r(a%b))
(단, b가 0이면 GCD는 a)
LCM = a*b/GCD(a,b)
*/

#include<iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}

int main() {
	int t;

	cin >> t;

	int a, b;

	while (t--){
		cin >> a >> b;
		cout << a * b / GCD(a, b)<<endl;
	}

	return 0;
}
