#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int main() {
	int n;
	pair<int, int> meeting[100000];
	int res = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &meeting[i].second, &meeting[i].first);
	}

	sort(meeting, meeting + n); //������ �ð� �������� ����(pair first �������� ���ĵǾ ������ �Է¹����� �ݴ�� ����)
	
	int lastEndTime = 0;
	for (int i = 0; i < n; i++) {
		int start = meeting[i].second, end = meeting[i].first;
		if (lastEndTime <= start) {
			lastEndTime = end;
			res++;
		}
	}

	printf("%d", res);
}