#include<iostream>
#include<string>

using namespace std;

int main() {

	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] - 3 == 'A' - 1)
			printf("Z");
		else if(s[i] - 3 == 'A' - 2)
			printf("Y");
		else if (s[i] - 3 == 'A' - 3)
			printf("X");
		else 
			printf("%c", s[i] - 3);
	}

}