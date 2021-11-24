//반복문 중첩으로 브루트 포스구현(N개에서 3개를 뽑는 경우의 수 찾기)
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
