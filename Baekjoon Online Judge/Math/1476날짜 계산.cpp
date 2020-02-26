#include<iostream>
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;

	int te = 0, ts = 0, tm = 0;
	int year = 0;

	while (1) {
		te++, ts++, tm++;
		if (te > 15) te = 1;
		if (ts > 28) ts = 1;
		if (tm > 19) tm = 1;
		year++;
		if (E == te && S == ts && M == tm)
			break;
	}
	printf("%d", year);
}