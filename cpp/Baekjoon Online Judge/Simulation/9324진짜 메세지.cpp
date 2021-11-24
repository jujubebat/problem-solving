#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		map<char, int> m;

		bool flag = true;

		for (int i = 0; i < str.size(); i++) {
			m[str[i]]++;
			if (m[str[i]] % 3 == 0) {
				if(i == str.size()-1) {
					flag = false; break;
				}
				if (str[i] != str[i + 1]) {
					flag = false; break;
				}
				i++;
			}
		}

		if (flag) {
			cout << "OK" << endl;
		}
		else
			cout << "FAKE" << endl;

	}

	return 0;
}