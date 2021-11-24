/***************
date : 20/02/01
design time : 20 min
implementation time : 15 min
debugging time : 30 min
****************/

//L���� ���ĺ� �ҹ���
//�ּ� �Ѱ��� ����, �ּ� �� ���� ����, ������������
//������ ������ c���� 
//���ɼ� �ִ� ��ȣ�� ��� ���ϱ�.
//���� //!! �����̾���
//���� : a, e, i, o, u
//a t c i s w
//1 5 2 3 4 6

//����, dfs
//������ ���� ���ĺ��� ���� ���ĺ� ���� Ŀ����
//����ϱ� ���� �ּ� ���� �������θ� Ȯ���ؾ���(���������� üũ)
//����ġ�� ���� : �������� ���� �����, �ּ����� ���� ����� 

//n������ m���� �̴� ������ �����ϵ� ��ȣ�� ������ �������
//�ִ� 15������ 15���� �̴� ��찡 ����, �̰�� �ð� ���⵵�� �ſ�Ŭ ������ ����
//���� ����ġ�⸦ ���ؾ���. 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int l, c;
vector<char> res;
char arr[15]; //�ĺ� ���ĺ�
bool visited[15];

void dfs() {
	if (res.size() == l) {//��ȣ�� �ϼ��Ǹ� ���
		//�ּ� ���� �������� Ȯ��(���⼭ �ϸ� �ð����⵵ �ʰ� �����)
		int a = 0, b = 0;
		for (char i : res) {
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
				a++;
			}
			else {
				b++;
			}
		}

		if (a < 1 || b < 2) return;

		for (char i : res) {
			printf("%c", i);
		}
		puts("");
		return;
	}

	//������ ������ �߰��Ͽ� Ǭ�ٰ�����ߴµ�, �̰��� �� �����̾���..
	for (int i = 0; i < c; i++) {
		if (!visited[i]) {
			if (!res.empty()) {
				if (res.back() < arr[i]) { //���� ������ ������ ���Һ��� ũ�ٸ�
					visited[i] = true;
					res.push_back(arr[i]);
					dfs();
					res.pop_back();
					visited[i] = false;
				}
			}
			else {
				visited[i] = true;
				res.push_back(arr[i]);
				dfs();
				res.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d", &l, &c);
	getchar();

	for (int i = 0; i < c; i++) {
		scanf("%c", &arr[i]);
		getchar();
	}

	sort(arr, arr + c);
	dfs();

	return 0;
}