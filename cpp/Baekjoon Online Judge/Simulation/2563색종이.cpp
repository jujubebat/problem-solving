/*#include<iostream>
using namespace std;

int map[100][100];

int main() {
	int n;
	int x, y;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		y = 99 - y;
		for (int a = y; a > y-10; a--) {
			for (int b = x; b < x+10; b++) {
				if (map[a][b] == 0) {
					map[a][b] = 1;
					res++;
				}
			}
		}
	}

	
	printf("%d", res);
}

*/
#include <cstdio>
using namespace std;

bool v[100][100];
int main()
{
	int n, i, j, x, y, c = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &x, &y);
		for (i = x; i < x + 10; i++)
			for (j = y; j < y + 10; j++)
				v[j][i] = true;
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			printf("%d ", v[i][j]);
		}
		puts("");
	}
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			if (v[i][j])
				c++;
	printf("%d", c);
}