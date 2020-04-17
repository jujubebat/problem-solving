#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n;
int capability[11][11];
int res = -0x7fffffff;
bool visited[11];
vector<int> v;

void permutation() {
	if (v.size() == 11) {
		int sum = 0;
		for (int i = 0; i < 11; i++) {
			sum += capability[i][v[i]]; //i번 선수에 v[i] 포지션을 줬을 때의 능력치 계산
		}
		res = max(res, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!visited[i] && capability[v.size()][i] != 0) {//포지션이 0이라면, 순열을 만들지 않는다. 
			visited[i] = true;
			v.push_back(i);
			permutation();
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;

	while (n--) {//테스트 케이스 n개
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> capability[i][j]; //선수들의 능력치를 입력받는다.
			}
		}
		permutation(); 
		cout << res << endl;
		res = -0x7fffffff;
	}

	return 0;
}