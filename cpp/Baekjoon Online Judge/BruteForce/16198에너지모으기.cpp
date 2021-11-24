/*
��ͷ� �ݺ�
���� �迭ũ�Ⱑ 2�϶�, �ִ� ����
���� ���Ŵ� ���� erase ���
ù��° ������ ������ ������ �� �� ����.
2��° �������� ������ ���� ���� ���� �ʴ� ���� ������ ���
������ ������ �� �ȵǴ� ���� �迭 �־��൵ �ð��ʰ� ���� �߻� x
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