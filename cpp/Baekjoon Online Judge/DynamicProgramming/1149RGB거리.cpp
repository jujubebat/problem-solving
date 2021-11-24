#include<iostream>
#include<algorithm>
using namespace std;

int d[1000][3]; 
int color[1000][3]; //���� 0, �ʷ� 1, �Ķ� 2

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}
	
	d[0][0] = color[0][0]; //0��° ������ ĥ���� �� �ּ� ���. ��, 0��° ���� ����
	d[0][1] = color[0][1]; //0��° ������ ĥ���� �� �ּ� ���. ��, 1��° ���� �ʷ�
	d[0][2] = color[0][2]; //0��° ������ ĥ���� �� �ּ� ���. ��, 2��° ���� �Ķ�

	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + color[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + color[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + color[i][2];
	}

	cout << min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2]));
}

// d[i][0]�� i���� ĥ������ �ּ� ���, i�� ����
// d[i][1]�� i���� ĥ������ �ּ� ���, i�� �ʷ�
// d[i][2]�� i���� ĥ������ �ּ� ���, i�� �Ķ�