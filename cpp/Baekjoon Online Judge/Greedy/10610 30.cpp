//30�� ����� ���� ��Ģ�� ã�´�.
//ù°�ڸ��� 0�̰� ������ �ڸ��� �������� 3�� �����. 
//�迭���ٰ� ���� ������ ����ְ�, ū������ ����Ѵ�.
//�Ŵܰ� ���� ���� ���� ����� �����ϴ� �׸��� �˰���

#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int n, sum = 0;
	int arr[10] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		n = s[i] - '0';
		sum += n;
		arr[n]++;
	}

	if (arr[0] == 0 || sum % 3 != 0) {
		printf("-1\n");
		return 0;
	}


	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++)
			printf("%d", i);
	}

	printf("\n");
	return 0;
}