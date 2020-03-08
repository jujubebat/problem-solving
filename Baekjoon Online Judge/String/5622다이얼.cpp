#include<iostream>
#include<string>
using namespace std;

int main() {
	int dial[10] = { 3,4,5,6,7,8,9,10,11 };
	string s;

	cin >> s;

	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'C') {
			res += dial[0];
		} 
		else if (s[i] >= 'D' && s[i] <= 'F') {
			res += dial[1];
		}
		else if (s[i] >= 'G' && s[i] <= 'I') {
			res += dial[2];
		}
		else if (s[i] >= 'J' && s[i] <= 'L') {
			res += dial[3];
		}
		else if (s[i] >= 'M' && s[i] <= 'O') {
			res += dial[4];
		}
		else if (s[i] >= 'P' && s[i] <= 'S') {
			res += dial[5];
		}
		else if (s[i] >= 'T' && s[i] <= 'V') {
			res += dial[6];
		}
		else if (s[i] >= 'W' && s[i] <= 'Z') {
			res += dial[7];
		}
	}

	cout << res;
	return 0;
}
