#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	string s;
	int ret = 0;
	cin >> s;

	// ��� ������ ���ϱ� ���� �������ش�. 
	sort(s.begin(), s.end());

	do {
		// ������ ���ڰ� ������ üũ�Ѵ�.
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