#include<iostream> 
#include<deque>
#include<string>
using namespace std;

int main() {
	string s;
	
	int cnt = 0; //��

	while (1) {
		int res = 0; //���
		cnt++;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-') // '-'�����ϸ� ����
				return 0;
		}

		deque<char> dq;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{')
				dq.push_back(s[i]);
			else if (s[i] == '}') {
				if (!dq.empty() && dq.back() == '{') {
					dq.pop_back();
				}
				else
					dq.push_back(s[i]);
			}
		}

		char a,b;

		while (!dq.empty()){
			a = dq.front();
			dq.pop_front();
			b = dq.front();
			dq.pop_front();

			if (a == '{' && b == '{')
				res++;
			else if (a == '}' && b == '}')
				res++;
			else if (a == '}' && b == '{')
				res += 2;

		}

		printf("%d. %d\n", cnt, res);

	}

	return 0;
}