
//�������� Ǭ �����
/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
bool flag = false;
int arr[9];


void dfs(int cnt, int height) {
	if (flag) return;

	if (v.size() == 7) {
		if (height == 100) {
			for (int i = 0; i < 7; i++) {
				printf("%d\n", arr[v[i]]);
			}

			flag = 1;
		}
		return;
	}

	for (int i = cnt; i < 9; i++) {
		v.push_back(i);
		height += arr[i];
		dfs(cnt + 1, height);
		height -= arr[i];
		v.pop_back();
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + 9);
	dfs(0,0);
}*/

//�ξ� ������ ���̵��
//9 �������� ���� �켱���ϰ�, �� ���� ������ Ű�� ������ ���� 100�� �Ǵ� ��� ���

#include<iostream>
#include<algorithm>

using namespace std;

int arr[9], sum = 0;

void solve() {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						printf("%d\n", arr[k]);
					}
				}
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	
	sort(arr, arr + 9);
	solve();
	return 0;
}