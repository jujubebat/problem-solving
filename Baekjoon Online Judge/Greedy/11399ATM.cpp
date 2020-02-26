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
	// 정렬을 통해 매단계에서 가장 좋은 방법(이 문제에서는 시간이 가장 적게 걸리는 사람)방법을 선택한다.
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			res += person[j];
		}
	}

	printf("%d", res);
}