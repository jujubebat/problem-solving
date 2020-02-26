//스스로 혼자 구현한 코드는 테스트 케이스는 맞았으나 채점에서 틀렸다고 나옴
//틀린 구현이었고 효율적이지도 않았었음
//다음의 아이디어로 손쉽게 구현할 수 있었음 -> 행+열이 짝수인 칸은 모두 같은색이, 행+열이 홀수인 칸도 모두 같은색임
#include<iostream>

using namespace std;

int n, m;
char board[50][50];

int checkBoard(int a, int b) {

	int cnt=0;
	int aCnt = 0, bCnt = 0; 
	//aCnt : 맨위 왼쪽이 흰색일때, 다시 칠해야하는 수
    //bCnt : 맨위 왼쪽이 검은색일때, 다시 칠해야하는 수

	for (int i = a; i <= a + 7; i++) {
		for (int j = b; j <= b + 7; j++) {
			
			if ((i + j) % 2 == 0) {//i+j 짝수칸
				if (board[i][j] != 'W')
					aCnt++;
				if (board[i][j] != 'B')
					bCnt++;
			}
			else if ((i + j) % 2 != 0) {//i+j 홀수칸
				if (board[i][j] != 'B')
					aCnt++;
				if (board[i][j] != 'W')
					bCnt++;
			}
		}
	}
	//흰검흰검... or 검흰검흰... 두가지로 바꾸기 위해 칠해야하는
	//정사각형의 개수중 작은 것 리턴
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