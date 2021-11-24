//ȥ�� �����ؼ� Ǭ �ڵ�
/*
//4������ n-1���� �̴� ����
//���� ������ ���� ����Ͽ� �ּڰ� �ִ��� ã��
#include<iostream>
#include<vector>

using namespace std;

int n;
int min = 2147483647, max=-2147483647;
vector<int> nums;
vector<char> opers;
vector<char> resOpers;
bool visited[10];


int calcul() {
	int a, b;
	int cnt=0;
	for (int i = 1; i < nums.size(); i++) {
		if(i==1) a = nums[i-1];
		b = nums[i];
		if (resOpers[cnt] == '+')
			a = a + b;
		else if (resOpers[cnt] == '-')
			a = a - b;
		else if (resOpers[cnt] == '*')
			a = a * b;
		else if (resOpers[cnt] == '/')
			a = a / b;
		cnt++;
	}
	return a;
}

void dfs() {
	if (resOpers.size() == n-1) {
		int num = calcul();

		if (num > max)
			max = num;

		if (num < min)
			min = num;

		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			resOpers.push_back(opers[i]);
			dfs();
			resOpers.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	int num;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			if (i == 0) opers.push_back('+');
			if (i == 1) opers.push_back('-');
			if (i == 2) opers.push_back('*');
			if (i == 3) opers.push_back('/');
		}
	}

	dfs();

	printf("%d\n", max);
	printf("%d\n", min);
}*/

//���� �ڵ�
/*
#include <stdio.h>

int n;
int number[11];
int op[4];
int ret_min = 0x7fffffff, ret_max = ret_min * -1;

void dfs(int result, int count) {
	if (count == n - 1) {
		if (ret_min > result) ret_min = result;
		if (ret_max < result) ret_max = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			--op[i];
			if (i == 0) dfs(result + number[count + 1], count + 1);
			if (i == 1) dfs(result - number[count + 1], count + 1);
			if (i == 2) dfs(result * number[count + 1], count + 1);
			if (i == 3) dfs(result / number[count + 1], count + 1);
			++op[i];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	dfs(number[0], 0);

	printf("%d\n%d\n", ret_max, ret_min);
	return 0;
}
*/

// �ٽ�Ǭ �ڵ�
#include<iostream>
#include<algorithm>
using namespace std;

int a[100];
int op[4];
int n;
int maxRet = -0x7fffffff, minRet = 0x7fffffff;

void solve(int idx, int sum) {

	if (idx == n) {
		maxRet = max(maxRet, sum);
		minRet = min(minRet, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		op[i]--;
		if (i == 0) { // +
			solve(idx + 1, sum + a[idx]);
		}
		else if (i == 1) { // -
			solve(idx + 1, sum - a[idx]);
		}
		else if (i == 2) { // x
			solve(idx + 1, sum * a[idx]);
		}
		else if (i == 3) { // /
			solve(idx + 1, sum / a[idx]);
		}
		op[i]++;
	}

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	solve(1, a[0]);

	cout << maxRet << endl << minRet;
	return 0;
}