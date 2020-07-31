#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string target;
	cin >> target;

	string first = "";
	string second = "";
	bool flag = true;

	for (int i = 0; i < target.size(); i++) {
		if (target[i] == '*') {
			flag = false;
			continue;
		}

		if (flag)
			first += target[i];
		else
			second += target[i];
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str.substr(0, first.size()).compare(first) == 0
				&& str.size()-first.size() >= second.size()
				&& str.substr(str.size() - second.size(), second.size()).compare(second) == 0) {
			cout << "DA" << endl;
			continue;
		}

		cout << "NE" << endl;
	}


	return 0;
}