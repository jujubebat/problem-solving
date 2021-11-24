#include<iostream>

using namespace std;

int out[4], in[4];
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &out[i], &in[i]);
	}

	int sum = 0;
	int res = -1e9;
	for (int i = 0; i < 4; i++) {
		sum -= out[i];
		sum += in[i];
		if (sum > res)
			res = sum;
	}

	printf("%d", res);
}