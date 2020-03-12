//배열에 a, c, i, n, t  는 항상 ture 나머지 알파벳 고르면 true표시
//나머지 알파벳에서 2개 고를 수 있음
//2개 고르는 조합. go or not으로 구현가능.
/*
+r,x

rc
hello
car*/

/*
고르고 검사하고.
모든 단어에 대해 idx 4부터 ~ idx n-5까지만 검사

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
	
	if (!arphabet[idx]) { //고르는 경우
		arphabet[idx] = true;
		dfs(idx + 1, cnt - 1);
		arphabet[idx] = false;
	}

	dfs(idx + 1, cnt); //안고른느 경우 
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