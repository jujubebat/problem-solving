#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C'
			|| str[i] == 'A'
			|| str[i] == 'M'
			|| str[i] == 'B'
			|| str[i] == 'R'
			|| str[i] == 'I'
			|| str[i] == 'D'
			|| str[i] == 'G'
			|| str[i] == 'E') {
			str.erase(str.begin() + i);
			i--;
		}
	}

	cout << str; 

	return 0;
}