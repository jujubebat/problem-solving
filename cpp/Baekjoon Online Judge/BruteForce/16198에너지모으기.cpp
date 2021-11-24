/*
재귀로 반복
구슬 배열크기가 2일때, 최댓값 갱신
구슬 제거는 벡터 erase 사용
첫번째 구슬과 마지막 구슬은 고를 수 없음.
2번째 구슬부터 구슬을 고르는 경우와 고르지 않는 경우로 나눠서 재귀
구슬의 개수가 얼마 안되니 구슬 배열 넣어줘도 시간초과 문제 발생 x
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> arr;
int res = -1;

void dfs(vector<int> arr, int sum) {
	if (arr.size() == 2) {
		res = max(res, sum);
		return;
	}
	
	vector<int> tmp;

	for (int i = 1; i < arr.size()-1; i++) {
		tmp = arr;
		tmp.erase(tmp.begin() + i);
		dfs(tmp, sum + arr[i - 1] * arr[i + 1]);
	}
}

int main() {
	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	dfs(arr,0);
	printf("%d", res);
	
	return 0;
}