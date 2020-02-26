//조합
#include<iostream>
#include<vector>

using namespace std;

int k;
vector<int>res_v;
vector<int> v;

void dfs(int n) {
	if (res_v.size()==6) {//경우의 수 출력
		for (int i : res_v) {
			printf("%d ", i);
		}
		puts("");
		return;
	}

	for (int i = n; i < k; i++) {
		res_v.push_back(v[i]);
		dfs(i + 1);
		res_v.pop_back();
	}
}

int main() {
	int num;
	while (1)
	{
		cin >> k;
		if (k == 0)
			return 0;

		v.clear();
		res_v.clear();
		for (int i = 0; i < k; i++) {
			cin >> num;
			v.push_back(num);
		}
		dfs(0);
		puts("");
	}
	
}