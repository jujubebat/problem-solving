#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

char arr[10][10];

int main() {
	map<char, int> map;

	map['A'] = 2;
	map['B'] = 2;
	map['C'] = 2;

	arr[2][0] = 'A';
	arr[2][1] = 'B';
	arr[2][2] = 'C';

	map['D'] = 3;
	map['E'] = 3;
	map['F'] = 3;

	arr[3][0] = 'D';
	arr[3][1] = 'E';
	arr[3][2] = 'F';

	map['G'] = 4;
	map['H'] = 4;
	map['I'] = 4;

	arr[4][0] = 'G';
	arr[4][1] = 'H';
	arr[4][2] = 'I';

	map['J'] = 5;
	map['K'] = 5;
	map['L'] = 5;

	arr[5][0] = 'J';
	arr[5][1] = 'K';
	arr[5][2] = 'L';

	map['M'] = 6;
	map['N'] = 6;
	map['O'] = 6;

	arr[6][0] = 'M';
	arr[6][1] = 'N';
	arr[6][2] = 'O';

	map['P'] = 7;
	map['Q'] = 7;
	map['R'] = 7;
	map['S'] = 7;

	arr[7][0] = 'P';
	arr[7][1] = 'Q';
	arr[7][2] = 'R';
	arr[7][3] = 'S';

	map['T'] = 8;
	map['U'] = 8;
	map['V'] = 8;

	arr[8][0] = 'T';
	arr[8][1] = 'U';
	arr[8][2] = 'V';

	map['W'] = 9;
	map['X'] = 9;
	map['Y'] = 9;
	map['Z'] = 9;

	arr[9][0] = 'W';
	arr[9][1] = 'X';
	arr[9][2] = 'Y';
	arr[9][3] = 'Z';

	int p, w;

	cin >> p >> w;
	getchar();

	string str;
	getline(cin, str);

	int ret = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			ret += p;
			continue;
		}

		int key = map[str[i]];
		int col;

		for (col = 0; col < 4; col++) {
			if (arr[key][col] == str[i]) break;
		}
		ret += (col + 1) * p;
	}

	int cnt = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == ' ') continue;
		if (map[str[i - 1]] == map[str[i]])
			cnt++;
	}

	ret += cnt * w;
	cout << ret;
	return 0;
}