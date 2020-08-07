#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;

	for (char tmp : str) {
		if (tmp == 'a'
			|| tmp == 'e'
			|| tmp == 'i'
			|| tmp == 'o'
			|| tmp == 'u')
			cnt++;
	}


	cout << cnt;
	return 0;
}