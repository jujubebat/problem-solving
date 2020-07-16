#include<iostream>
#include<string>
using namespace std;

char map[5][500];
char wenddy[5][5] = {
{'.','.','*','.','.'},
{'.','*','.','*','.'},
{'*','.','X','.','*'},
{'.','*','.','*','.'},
{'.','.','*','.','.'},
};

char peterfan[5][5] = {
{'.','.','#','.','.'},
{'.','#','.','#','.'},
{'#','.','X','.','#'},
{'.','#','.','#','.'},
{'.','.','#','.','.'},
};

int main() {
	string str;
	cin >> str;

	int col = 0;

	for (int i = 0; i < str.size(); i++) {

		if ((i + 1)% 3 == 0) { //À¢µð
			for (int r = 0; r <5 ; r++) {
				for (int c = col; c < col + 5; c++) {
					map[r][c] = wenddy[r][c-col];
				}
			}
		}
		else {
			for (int r = 0; r < 5; r++) {
				for (int c = col; c < col + 5; c++) {
					if (map[r][c] == '*') continue;
					map[r][c] = peterfan[r][c - col];
				}
			}
		}

		map[2][col + 2] = str[i];
		col += 4;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j< 5 * str.size() - (str.size() - 1); j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}