#include<iostream>

using namespace std;

int main() {
	int n, m, k;
	int res = 0;
	cin >> n >> m >> k;

	while(1){
		n -= 2, m -= 1; //����-2, ����-1
		if (n < 0 || m < 0)
			break;
		if (n + m < k) //���� ����+���� �ο��� k���� �۴ٸ�, �� �׸� �����
			break;
		res++; //���� ����
	}
	printf("%d", res);
}

/*
6 4 1

6 4 
4 3 1
2 2 2
0 1 3
-2 0
*/
