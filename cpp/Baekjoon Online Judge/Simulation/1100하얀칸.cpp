/*������������
�������������*/

#include<iostream>
using namespace std;


int main() {

	int map[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					map[i][j] = 0; // ��
				}
				else {
					map[i][j] = 1; // ��
				}
			}
			else {
				if (j % 2 != 0) {
					map[i][j] = 0;
				}
				else {
					map[i][j] = 1;
				}
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char input;
			cin >> input;
			if (map[i][j] == 0 && input == 'F')
				ret++;
		}
	}
	
	cout << ret;

	return 0;
}
