#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	string s;
	int ret = 0;
	cin >> s;

	// 모든 순열을 구하기 위해 정렬해준다. 
	sort(s.begin(), s.end());

	do {
		// 인접한 문자가 같은지 체크한다.
		bool flag = false;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		ret++;

	} while (next_permutation(s.begin(), s.end()));

	cout << ret;
}