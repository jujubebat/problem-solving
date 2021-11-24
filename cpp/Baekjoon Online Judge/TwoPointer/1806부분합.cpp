#include<iostream>
#include<algorithm>
using namespace std;

int n, s;
int arr[100000];
int res = 0x7fffffff; //�ּҰ��� ���� ���̹Ƿ� int ���� �ִ밪���� �ʱ�ȭ�Ѵ�. 

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//�������� ����Ű�� ������, ������ ����Ű�� ������, ���� �� 
	int start = 0, end = 0, sum = 0;

	while (end <= n) {
		if (sum < s) { //�������� s���� ������ end�� ����
			sum += arr[end++];
		}
		else if (sum > s) {//�������� s���� ũ�� start�� ����
			res = min(res, end - start); //���� ���� �ּҰ� ����
			sum -= arr[start++];
		}
		else if (sum == s) {//�������̶� s�� ������ end�� ����
			res = min(res, end - start); //���� ���� �ּҰ� ����
			sum += arr[end++];
		}
	}
	
	if (res == 0x7fffffff) //���ǿ� �´� �������� ���� ���
		cout << 0;
	else
		cout << res;

	return 0;
}