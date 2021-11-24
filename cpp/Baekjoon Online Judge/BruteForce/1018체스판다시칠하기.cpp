//������ ȥ�� ������ �ڵ�� �׽�Ʈ ���̽��� �¾����� ä������ Ʋ�ȴٰ� ����
//Ʋ�� �����̾��� ȿ���������� �ʾҾ���
//������ ���̵��� �ս��� ������ �� �־��� -> ��+���� ¦���� ĭ�� ��� ��������, ��+���� Ȧ���� ĭ�� ��� ��������
#include<iostream>

using namespace std;

int n, m;
char board[50][50];

int checkBoard(int a, int b) {

	int cnt=0;
	int aCnt = 0, bCnt = 0; 
	//aCnt : ���� ������ ����϶�, �ٽ� ĥ�ؾ��ϴ� ��
    //bCnt : ���� ������ �������϶�, �ٽ� ĥ�ؾ��ϴ� ��

	for (int i = a; i <= a + 7; i++) {
		for (int j = b; j <= b + 7; j++) {
			
			if ((i + j) % 2 == 0) {//i+j ¦��ĭ
				if (board[i][j] != 'W')
					aCnt++;
				if (board[i][j] != 'B')
					bCnt++;
			}
			else if ((i + j) % 2 != 0) {//i+j Ȧ��ĭ
				if (board[i][j] != 'B')
					aCnt++;
				if (board[i][j] != 'W')
					bCnt++;
			}
		}
	}
	//������... or �������... �ΰ����� �ٲٱ� ���� ĥ�ؾ��ϴ�
	//���簢���� ������ ���� �� ����
	if (aCnt < bCnt)
		return aCnt;
	else
		return bCnt;
}
 
int main() {
	int min = 50000;
	int tmp;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 7 >= n || j + 7 >= m)
				continue;
			tmp = checkBoard(i, j);

			if (min > tmp)
				min = tmp;
		}
	}

	printf("%d", min);
}