#include<iostream>
#include<string>
using namespace std;

int main() {

	int n;

	cin >> n;

	string ret;

	while (n--) {
		string str;
		cin >> str;

		if (ret.size() == 0) {
			ret = str;
		}
		for (int i = 0; i < ret.size(); i++) {
			if (ret[i] != str[i])
				ret[i] = '?';
		}
	}
	
	cout << ret;

	return 0;
}