#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int person[1000];
	int n;
	int res = 0;

	cin >> n; 

	for (int i = 0; i < n; i++) {
		scanf("%d", &person[i]);
	}

	sort(person, person + n);
	// ������ ���� �Ŵܰ迡�� ���� ���� ���(�� ���������� �ð��� ���� ���� �ɸ��� ���)����� �����Ѵ�.
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			res += person[j];
		}
	}

	printf("%d", res);
}