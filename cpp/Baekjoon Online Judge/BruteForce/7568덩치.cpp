#include<iostream>

using namespace std;

typedef struct {
	int w, h;
}person;
int main() {
	int n;
	person p[50];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i].w >> p[i].h;
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (p[i].w < p[j].w && p[i].h < p[j].h)
				cnt++;
		}
		printf("%d ", cnt + 1);
	}
}