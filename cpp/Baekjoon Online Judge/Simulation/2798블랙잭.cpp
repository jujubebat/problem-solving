//�ݺ��� ��ø���� ���Ʈ ��������(N������ 3���� �̴� ����� �� ã��)
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	int N, M;
	int card[100];
	int sum, res;
	int max = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				//printf("%d %d %d\n", i, j, k);
				int sum = card[i] + card[j] + card[k];
				if (sum>max && sum<=M) {
					max = sum;
				}
			}
		}
	}
	cout << max;
}
