//ȥ�� ������ �����ɷ� Ǯ����
//�� ���� ����� �־ ������
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string str;
	int res = 0;

	cin >> n;
	int cnt = 0;

	// ��� ��� (%1000���� 3�ڸ��� 666���� �ѹ��� Ȯ��)
	for (long long i = 666; ; i++) {
		long long num = i;
		while (num >= 666)
		{
			if (num % 1000 == 666) {
				cnt++;
				if (cnt == n) {
					cout << i;
					return 0;
				}
				break;
			}
			num /= 10;
		}
	}
	

	//���� § ���( %10���� ���ڸ��� �˻��ؼ� �������� 6���� Ȯ��)
	/*
	for (int i = 666; ; i++) {
		int cnt = 0,num=i;

		while (num > 0) {
			if (num % 10 == 6)
				cnt++;
			else
				cnt = 0;

			if (cnt == 3) {
				res++;
				break;
			}
			num /= 10;
		}

		if (res == n) {
			printf("%d", i);
			break;
		}
	}*/
}