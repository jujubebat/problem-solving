#include<iostream>	
#include<string>
using namespace std;

int main() {
	string s;
	
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		putchar(s[i]);
		if (i % 10 == 9)
			puts("");
	}
	return 0;
}