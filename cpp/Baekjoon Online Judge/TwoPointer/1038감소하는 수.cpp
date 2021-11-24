#include<iostream>
#include<queue>
using namespace std;

queue<long long> q;
long long arr[1000001]; //n�� �ִ밪�� 1000000�̴�, long long �ڷ����� ����Ѵ�.

int main() {
	
	for (int i = 0; i <= 9; i++) //0~9���� ť�� �־��ش�.
		q.push(i);

	int idx = 0; //�迭 ���������� ���� �ε���

	while (!q.empty()) { 
		long long num = q.front(); //ť���� ���Ҹ� �ϳ��� ������,
		arr[idx++] = num; //�迭�� ���������� �ִ´�.
		if (idx > 1000000) break; //idx(n)�� 1000000���� ũ�� ����
		q.pop();

		//ť���� ���� ������ �̾����� �����ϴ� ���� ����� ť�� �־��ش�.
		for (int i = 0; i < 10; i++) { 
			if (num % 10 > i) { //���� 1�� �ڸ������� ���� ���� ���,
				long long tmp = num * 10 + i; //�����ϴ� ���� �����.
				q.push(tmp);
			}
		}
	}

	//�����ϴ� ���� 1023��°���ʹ� �������� �ʴ´�. (1022��° �����ϴ� ���� 9,876,543,210 �̴�.)

	int n;
	cin >> n;
	if (n > 1022) 
		cout << -1;
	else
		cout << arr[n]; //n��° �����ϴ� ���� ����Ѵ�.

	return 0;
}
