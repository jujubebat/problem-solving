//혼자 생각해서 푼 코드
/*
//4개에서 n-1개를 뽑는 순열
//뽑은 다음에 수를 계산하여 최솟값 최댓값을 찾음
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

//좋은 코드

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