//�迭�� a, c, i, n, t  �� �׻� ture ������ ���ĺ� ���� trueǥ��
//������ ���ĺ����� 2�� �� �� ����
//2�� ���� ����. go or not���� ��������.
/*
+r,x

rc
hello
car*/

/*
���� �˻��ϰ�.
��� �ܾ ���� idx 4���� ~ idx n-5������ �˻�

2500+

1.3168189e+13*/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool arphabet[26];
char prior[5] = { 'a', 't', 'n', 'i', 'c' };
int n, k;
string words[50];
int res = 0;

void dfs(int idx, int cnt) {

	if (cnt == 0) {
		int sum = 0;
		bool flag;
		for (int i = 0; i < n; i++) {
			flag = true;
			for (int j = 0; j < words[i].size(); j++) {
				if (!arphabet[words[i][j] - 'a'])
					flag = false;
			}
			if (flag) sum++;
		}

		res = max(res, sum);
		return;
	}

	if (idx >= 26) return;
	
	if (!arphabet[idx]) { //���� ���
		arphabet[idx] = true;
		dfs(idx + 1, cnt - 1);
		arphabet[idx] = false;
	}

	dfs(idx + 1, cnt); //�Ȱ��� ��� 
}

int main() {
	cin >> n >> k;

	int i;
	for (i = 0; i < k; i++) {
		if (i == 5) break;
		arphabet[prior[i]-'a'] = true;
	}
	k -= i;
	
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	dfs(0,k);
	printf("%d", res);

	return 0;
}