#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	str.insert(str.begin(), '*');

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'S') 
			str.insert(str.begin() + i +1, '*');
		if (str[i] == 'L' && str[i + 1] == 'L') 
			str.insert(str.begin() + i + 2, '*');
	}

	int ret = 0;
	for (int i = 0; i < str.size(); i ++) {
		if (str[i] == 'S' || str[i] == 'L') {
			if (str[i - 1] == '*') {
				str[i - 1] = '#';
				ret++;
			}
			else if (str[i + 1] == '*') {
				str[i + 1] = '#';
				ret++;
			}
		}

	}
	cout << ret;
	return 0;
}

