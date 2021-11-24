//1~9���� n���� �̴´�. (����) -> �ϳ����������� �Ҽ����� üũ 
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
bool visited[10];
int n;

bool isPrime(int n) {//�Ҽ� �Ǻ�
	if (n == 0 || n == 1)
		return false;

	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

void dfs() {
	int num=0;
	for (int i = 0; i < v.size(); i++) { //���ڸ����
		if (num == 0)
			num += v[i];
		else {
			num *= 10;
			num += v[i];
		}
	}

	if (num != 0 && !isPrime(num))
		return;

	if (v.size() == n) {
		for (int x : v)
			printf("%d", x);
		puts("");
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (i != 0) {
			v.push_back(i);
			dfs();
			v.pop_back();
		}
	}
}

int main() {
	cin >> n;
	dfs();
	return 0;
}