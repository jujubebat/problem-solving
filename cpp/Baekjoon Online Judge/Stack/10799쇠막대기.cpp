//�������� == () ������ ��� ����⸦ �ڸ��� -> ���� size�� �̿��Ѵ�.
//��� ����ϴٰ� Ǯ�� ����. ������ �ٸ��� ���� �ð��� ��������

#include<iostream>
#include<stack>
#include<algorithm>	
#include<string>

using namespace std;

int main() {
	stack<char> st;
	string str;
	int res=0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			st.push(str[i]);
		else if (str[i] == ')') {
			st.pop();
			if (str[i - 1] == '(')
				res += st.size();
			else
				res += 1;
		}
	}

	cout << res;
}