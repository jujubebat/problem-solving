#include<iostream>
#include<string>
using namespace std;

int main() {
	int ga = 0, da = 0;

	string str;
	cin >> str;
	
	str = "|" + str;

	for (int i = 1; i < str.size(); i++) {

		if (str[i-1] != '|') continue;
		
		if (str[i] == 'A' || str[i] == 'D' || str[i] == 'E') {
			ga++;
		}

		if (str[i] == 'C' || str[i] == 'F' || str[i] == 'G') {
			da++;
		}
	}

	if (ga > da) {
		cout << "A-minor";
	}
	else if (ga == da) {
		if (str.back() == 'A' || str.back() == 'D' || str.back() == 'E') {
			cout << "A-minor";
		}

		if (str.back() == 'C' || str.back() == 'F' || str.back() == 'G') {
			cout << "C-major";
		}
	}
	else {
		cout << "C-major";
	}

	return 0;
}