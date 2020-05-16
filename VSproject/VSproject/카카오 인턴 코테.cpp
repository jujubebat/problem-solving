/*#include <string>
#include <vector>
#include<iostream>
using namespace std;

int left_x = 3, left_y = 0;
int right_x = 3, right_y = 2;
string g_hand;

char move(int number) {

	if (number == 1) {
		left_x = 0, left_y = 0;
		return 'L';
	}
	else if (number == 4) {
		left_x = 1, left_y = 0;
		return 'L';
	}
	else if (number == 7) {
		left_x = 2, left_y = 0;
		return 'L';
	}

	if (number == 3) {
		right_x = 0, right_y = 2;
		return 'R';
	}
	else if (number == 6) {
		right_x = 1, right_y = 2;
		return 'R';
	}
	else if (number == 9) {
		right_x = 2, right_y = 2;
		return 'R';
	}

	


	if (number == 2) {

		int leftDistance = abs(left_x - 0) + abs(left_y - 1);
		int rightDistance = abs(right_x - 0) + abs(right_y - 1);

		if (leftDistance < rightDistance) {
			left_x = 0, left_y = 1;
			return 'L';
		}
			
		else if (leftDistance > rightDistance){
			right_x = 0, right_y = 1;
			return 'R';
		}
		else {
			if (g_hand == "left") {
				left_x = 0, left_y = 1;
				return 'L';
			}
			else if (g_hand == "right") {
				right_x = 0, right_y = 1;
				return 'R';
			}
		}

	}
	else if (number == 5) {
		int leftDistance = abs(left_x - 1) + abs(left_y - 1);
		int rightDistance = abs(right_x - 1) + abs(right_y - 1);

		if (leftDistance < rightDistance) {
			left_x = 1, left_y = 1;
			return 'L';
		}

		else if (leftDistance > rightDistance) {
			right_x = 1, right_y = 1;
			return 'R';
		}
		else {
			if (g_hand == "left") {
				left_x = 1, left_y = 1;
				return 'L';
			}
			else if (g_hand == "right") {
				right_x = 1, right_y = 1;
				return 'R';
			}
		}
	}
	else if (number == 8) {
		int leftDistance = abs(left_x - 2) + abs(left_y - 1);
		int rightDistance = abs(right_x - 2) + abs(right_y - 1);

		if (leftDistance < rightDistance) {
			left_x = 2, left_y = 1;
			return 'L';
		}

		else if (leftDistance > rightDistance) {
			right_x = 2, right_y = 1;
			return 'R';
		}
		else {
			if (g_hand == "left") {
				left_x = 2, left_y = 1;
				return 'L';
			}
			else if (g_hand == "right") {
				right_x = 2, right_y = 1;
				return 'R';
			}
		}
		
	}
	else if (number == 0) {
		int leftDistance = abs(left_x - 3) + abs(left_y - 1);
		int rightDistance = abs(right_x - 3) + abs(right_y - 1);

		if (leftDistance < rightDistance) {
			left_x = 3, left_y = 1;
			return 'L';
		}

		else if (leftDistance > rightDistance) {
			right_x = 3, right_y = 1;
			return 'R';
		}
		else {
			if (g_hand == "left") {
				left_x = 3, left_y = 1;
				return 'L';
			}
			else if (g_hand == "right") {
				right_x = 3, right_y = 1;
				return 'R';
			}
		}

		
	}

}

string solution(vector<int> numbers, string hand) {
	string ret = "";
	g_hand = hand;

	for (int i = 0; i < numbers.size(); i++) {
		cout << left_x << " " << left_y << endl;
		cout << right_x << " " << right_y << endl;

		ret += move(numbers[i]);

	}

	return ret;
}*/
/*
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;

bool gflag = false;

bool isContain() {

	if (gflag) {
		gflag = false;
		return false;
	}
	
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second <= 0)
			return false;
	}

	return true;
}

vector<int> solution(vector<string> gems) {

	vector<int> answer;
	int size = gems.size();
	
	for (int i = 0; i < size; i++) {
		m[gems[i]] = 0;
	}

	if (size == m.size()) {
		answer.push_back(1);
		answer.push_back(size);
		return answer;
	}

	int minValue = 0x7fffffff;
	int start = 0, end = 0;
	int a = 0, b = 0;

	
	while (end < size && start < size) {

		if (start > end) break;

		if (!isContain()) {

			if (end == size - 1) {
				m.find(gems[start++])->second--;
				
				if (m.find(gems[start-1])->second <= 0)
					gflag = true;
			}
			else {
				m.find(gems[end++])->second++;
			}
		}
		else if (isContain()) {
			if (end - start < minValue) {
				minValue = end - start;
				a = start + 1;
				b = end;
				if (end - start == 0) break;
			}
			m.find(gems[start++])->second--;
			if (m.find(gems[start-1])->second <= 0)
				gflag = true;
		}

	}

	answer.push_back(a);
	answer.push_back(b);

	return answer;
}

int main() {
	vector<string> gems;

	gems.push_back("DIA");
	gems.push_back("RUBY");
	gems.push_back("DIA");
	gems.push_back("DIA");
	gems.push_back("EMERALD");
	gems.push_back("SAPPHIRE");
	gems.push_back("DIA");

	solution(gems);

	return 0;
}
*/

#include <string>
#include <vector>
#include <queue>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y, c, d;
}pos;

vector<vector<int>> map;
int ret = 2e9;
int visited[25][25][20000];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
int n, m;

//0123 상하좌우

//(이동한 길이 -1 * 100 ) + 코너카운트 * 500

void bfs() {
	queue<pos> q;
	q.push({ 0, 0, 0, -1});
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int c = q.front().c, d = q.front().d;
		q.pop();
	
		if (x == n - 1 && y == m - 1) {

			ret = min(ret, (visited[x][y][c]-1)*100 + c*500);
		}

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i], ny = y + dy[i];
			int nd = i, nc;

			if (d == i || d == -1) //같은 방향이면 코너카운트 증가 x
				nc = c;
			else {
				nc = c + 1;
			}

			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;

			if (map[nx][ny]) continue; //벽있으면 x

			if (visited[nx][ny][nc]) continue;

			if (nc > 20000) continue;


			visited[nx][ny][nc] = visited[x][y][c] + 1;
			q.push({ nx,ny,nc,nd });
		}
	}
}

int solution(vector<vector<int>> board) {

	n = board.size();
	m = board[0].size();
	map = board;

	bfs();

	return ret;
}

int main() {
	vector<vector<int>> board;
	vector<int> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);

	board.push_back(a);
	board.push_back(a);
	board.push_back(a);

	solution(board);


	cout << ret << endl;
	return 0;
}
