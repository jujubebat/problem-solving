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

	sort(meeting, meeting + n); //끝나는 시간 기준으로 정렬(pair first 기준으로 정렬되어서 위에서 입력받을때 반대로 받음)
	
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