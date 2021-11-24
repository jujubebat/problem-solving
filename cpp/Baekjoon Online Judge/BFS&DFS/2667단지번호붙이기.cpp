//������ ���� dfs, bfs�� �ذ��ؾ߰ڴٴ� ������ ��
//����� �ص� Ǯ ����� ������ �ȳ�
//Ǫ�� ����� ���� �ڵ带 ������
//dfs�� ������ ��ȸ�Ѵ�.
//��ȸ�� ���� ��ȣ�� 1���� 0���� �ٲپ���. 

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
	map[x][y] = 0; //�湮
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny<0 || ny >=N)continue; //���� ����� ��ŵ
		if (!map[nx][ny]) continue; //0�̶�� ��ŵ
		dfs(nx, ny);//dfs�� ������.
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) //�������,
			{
				cnt = 0;//���� ���� ī��Ʈ �ʱ�ȭ
				dfs(i, j);
				apt.push_back(cnt);//ī��Ʈ�� ���� ������ �迭�� �ִ´�.
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
	sort(apt.begin(), apt.end()); //���� �������� ����
	int len = apt.size();
	printf("%d\n", len); //���� ���� ���
	for (int i = 0; i < len; i++)
		printf("%d\n", apt[i]); //���� ��ȣ ���
	
	return 0;
}