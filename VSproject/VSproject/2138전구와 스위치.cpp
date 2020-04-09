#include<iostream>

using namespace std;

int start[100000];
int dest[100000];
int n;
int res = 0;

bool isSame() {
	
	for (int i = 0; i < n; i++) {
		if (start[i] != dest[i])
			return false;
	}

	return true;
}

void pushButton(int i) {

	res++;

	if (i == n) {
		start[n - 2] = start[n - 2] ? 0 : 1;
		start[n-1] = start[n - 1] ? 0 : 1;
	}
	else {
		start[i - 1] = start[i - 1] ? 0 : 1;
		start[i] = start[i] ? 0 : 1;
		start[i + 1] = start[i + 1] ? 0 : 1;
	}

	for (int i = 0; i < n; i++) {
		printf("%d", start[i]);
	}
	puts("");
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf_s("%1d", &start[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf_s("%1d", &dest[i]);
	}

	for (int i = 0; i < n; i++) {
		if (start[i] != dest[i])
			pushButton(i+1);
		if (isSame()) {
			printf("%d\n", res);
			return 0;
		}
	}

	printf("-1");
	return 0;
}