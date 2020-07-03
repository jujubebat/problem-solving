#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	string num;
	cin >> num;

	string a, b;

	a = num + "0000";
	b = "0000" + num;

	string ret = "";

	bool flag = false;

	for (int i = a.size(); i >= 0; i--) {

		if (a[i] != b[i]) {
			if (flag) {
				ret = "0" + ret;
				flag = true;
			}
			else {
				ret = "1" + ret;
				flag = false;
			}
		}
		else if (a[i] == '0' && b[i] == '0') {
			if (flag) {
				ret = "1" + ret;
				flag = false;
			}
			else {
				ret = "0" + ret;
				flag = false;
			}
		}
		else if (a[i] == '1' && b[i] == '1') {
			if (flag) {
				ret = "1" + ret;
				flag = true;
			}
			else {
				ret = "0" + ret;
				flag = true;
			}
		}

	}

	if (flag)
		ret = "1" + ret;
	cout << ret;
	return 0;
}