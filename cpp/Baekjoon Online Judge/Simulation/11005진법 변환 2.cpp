#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string convertNotaion(int n, int b) {

	string ret = "";

	while (n > 0) {
		//ret += ch[n%b];

		if (n%b < 10) {
			ret += (char)(n%b + '0');
		}
		else
			ret += (char)(n%b - 10 + 'A');

		n /= b;
	}

	reverse(ret.begin(), ret.end());
	return ret;

}

int main() {
	int n, b;
	cin >> n >> b;

	cout << convertNotaion(n, b);

	return 0;
}