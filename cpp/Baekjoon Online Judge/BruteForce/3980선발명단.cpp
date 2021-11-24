#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n;
int capability[11][11];
int res = -0x7fffffff;
bool visited[11];
vector<int> v;

void permutation() {
	if (v.size() == 11) {
		int sum = 0;
		for (int i = 0; i < 11; i++) {
			sum += capability[i][v[i]]; //i�� ������ v[i] �������� ���� ���� �ɷ�ġ ���
		}
		res = max(res, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!visited[i] && capability[v.size()][i] != 0) {//�������� 0�̶��, ������ ������ �ʴ´�. 
			visited[i] = true;
			v.push_back(i);
			permutation();
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;

	while (n--) {//�׽�Ʈ ���̽� n��
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> capability[i][j]; //�������� �ɷ�ġ�� �Է¹޴´�.
			}
		}
		permutation(); 
		cout << res << endl;
		res = -0x7fffffff;
	}

	return 0;
}