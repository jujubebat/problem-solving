#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	string a, b;

	unordered_map<char, int> m;

	cin >> a;
	cin >> b;

	for (char tmp : a) {
		m[tmp]++;
	}

	int commond = 0;

	for (char tmp : b) {
		if (m[tmp] > 0) {
			m[tmp]--;
			commond++;
		}
	}

	cout << a.size() - commond + b.size() - commond;
	return 0;
}