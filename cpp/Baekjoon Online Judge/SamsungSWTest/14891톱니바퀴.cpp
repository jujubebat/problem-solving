#include<iostream>
using namespace std;

int gear[4][8];
int gearNum[100], dir[100];

void rotation(int g, int d) {
	int left, right, tmp_g, tmp_d;
	int rotate[4] = { 0,0,0,0 };
	rotate[g] = d;

	tmp_g = g, tmp_d = d, left = g - 1;
	while (left >= 0){
		if (gear[tmp_g][6] != gear[left][2]) { //±ÿ¿Ã ¥Ÿ∏£¥Ÿ∏È
			rotate[left] = tmp_d * -1;
		}
		else
			break;
		tmp_g--, left--, tmp_d *= -1;
	}

	tmp_g = g, tmp_d = d, right = g + 1;
	while (right < 4) {
		if (gear[tmp_g][2] != gear[right][6]) { //±ÿ¿Ã ¥Ÿ∏£¥Ÿ∏È
			rotate[right] = tmp_d * -1;
		}
		else
			break;
		tmp_g++, right++, tmp_d *= -1;
	}

	for (int i = 0; i < 4; i++) {
		if (rotate[i] == 1) {
			int tmp[8];
			for (int j = 0; j < 7; j++) {
				tmp[j + 1] = gear[i][j];
			}
			tmp[0] = gear[i][7];
			
			for (int j = 0; j < 8; j++) {
				gear[i][j] = tmp[j];
			}
		}
		else if (rotate[i] == -1) {
			int tmp[8];
			for (int j = 1; j < 8; j++) {
				tmp[j -1] = gear[i][j];
			}
			tmp[7] = gear[i][0];

			for (int j = 0; j < 8; j++) {
				gear[i][j] = tmp[j];
			}
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> gearNum[i] >> dir[i];
	}

	for (int i = 0; i < k; i++) {
		rotation(gearNum[i]-1, dir[i]);
	}

	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {//s±ÿ
			if (i == 0) res += 1;
			else if (i == 1) res += 2;
			else if (i == 2) res += 4;
			else if (i == 3) res += 8;
		}
	}
	cout << res;
}