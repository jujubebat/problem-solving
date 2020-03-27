#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int n, k;

	cin >> n >> k;
	cin >> s;

	long long res = 0;
	int size = s.size();

	for (int i = 0; i < size; i++) {
		string tmp = "";
		bool flag = false;
		for (int j = i; j < i + k; j++) {
			if (j >= size) {
				flag = true;
				break;
			}
			tmp += s[j];
		}
		
		if (flag) 
			break;

		int num = stoi(tmp);
		res = max(res, num);
	}

	cout << res;

	return 0;
}
