#include<iostream>
#include<algorithm>
using namespace std;

int d[1000][3]; 
int color[1000][3]; //빨강 0, 초록 1, 파랑 2

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}
	
	d[0][0] = color[0][0]; //0번째 집까지 칠했을 때 최소 비용. 단, 0번째 집은 빨강
	d[0][1] = color[0][1]; //0번째 집까지 칠했을 때 최소 비용. 단, 1번째 집은 초록
	d[0][2] = color[0][2]; //0번째 집까지 칠했을 때 최소 비용. 단, 2번째 집은 파랑

	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + color[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + color[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + color[i][2];
	}

	cout << min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2]));
}

// d[i][0]는 i까지 칠했을때 최소 비용, i는 빨강
// d[i][1]는 i까지 칠했을때 최소 비용, i는 초록
// d[i][2]는 i까지 칠했을때 최소 비용, i는 파랑