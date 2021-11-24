/*
----����----
1.���ڸ� �ϳ��� �߰��Ѵ�.
2.�߰��� ��� ���� �������� �˻��Ѵ�.
  -���Ӱ� �߰��� �ǵ��ڸ� ���ں��� �ϳ��� ������Ű�� ��.
3.n�ڸ��� ���� ������ ����� ����ϰ� �����Ѵ�. 

---�󼼱��� ���� ---

dfs�� Ž���ϱ�, ���� ������ ��� ����ġŰ
1,2,3 ������ Ž�������� ���� ó�� ��������� ���� ���.
*/

//�� Ǯ��
/*
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
int flag = false;

bool isBad() {
	int size = v.size() / 2;

	for (int i = 1; i <= size; i++) {
		int last_idx = v.size() - 1;
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (v[last_idx] == v[last_idx - i])
				cnt++;
			last_idx--;
		}
		if (cnt == i)
			return true;
	}

	return false;
}

void dfs() {
	if (isBad())
		return;

	if (n == v.size()) {
		for (int x : v) {
			printf("%d", x);
		}
		flag = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
		dfs();
		if (flag)
			return;
		v.pop_back();
	}
}

int main() {
	cin >> n;
	dfs();
	return 0;
}

*/
#include <iostream>
#include <string>
using namespace std;

int n;
bool flag;

void dfs(string str) {
	if (flag) return;

	int len = str.length();
	for (int i = 1; i <= len / 2; i++) {
		if (str.substr(len - i, i) == str.substr(len - 2 * i, i)) {
			str = "";
			return;
		}
	}

	if (str.length() == n) {
		flag = true;
		cout << str << '\n';
		return;
	}
	
	dfs(str + '1');
	dfs(str + '2');
	dfs(str + '3');
}
int main() {
	cin >> n;
	dfs("");
	return 0;
}