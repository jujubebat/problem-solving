//문제를 보고 dfs, bfs로 해결해야겠다는 생각을 함
//고민을 해도 풀 방법이 생각이 안나
//푸는 방법과 정답 코드를 참조함
//dfs로 단지를 조회한다.
//조회한 단지 번호를 1에서 0으로 바꾸어줌. 

#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int map[25][25];
int N, cnt;
int dx[] = {0,0,-1,1 }, dy[] = {1,-1,0,0};
vector<int> apt;

void dfs(int x, int y) {
	map[x][y] = 0; //방문
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny<0 || ny >=N)continue; //범위 벗어나면 스킵
		if (!map[nx][ny]) continue; //0이라면 스킵
		dfs(nx, ny);//dfs를 돌린다.
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) //단지라면,
			{
				cnt = 0;//단지 개수 카운트 초기화
				dfs(i, j);
				apt.push_back(cnt);//카운트한 단지 개수를 배열에 넣는다.
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	solve();
	sort(apt.begin(), apt.end()); //단지 오름차순 정렬
	int len = apt.size();
	printf("%d\n", len); //단지 개수 출력
	for (int i = 0; i < len; i++)
		printf("%d\n", apt[i]); //단지 번호 출력
	
	return 0;
}