#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string str;
	
	cin >> str;

	string originStr = str;
	reverse(str.begin(), str.end());
	
	if (str.compare(originStr) == 0)
		cout << 1;
	else
		cout << 0;

	return 0;
}