#include<iostream>
#include<algorithm>
using namespace std;

int n, s;
int arr[100000];
int res = 0x7fffffff; //최소값을 구할 것이므로 int 범위 최대값으로 초기화한다. 

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//시작점을 가리키는 포인터, 끝점을 가리키는 포인터, 구간 합 
	int start = 0, end = 0, sum = 0;

	while (end <= n) {
		if (sum < s) { //구간합이 s보다 작으면 end를 증가
			sum += arr[end++];
		}
		else if (sum > s) {//구간합이 s보다 크면 start를 증가
			res = min(res, end - start); //구간 길이 최소값 갱신
			sum -= arr[start++];
		}
		else if (sum == s) {//구간합이랑 s랑 같으면 end를 증가
			res = min(res, end - start); //구간 길이 최소값 갱신
			sum += arr[end++];
		}
	}
	
	if (res == 0x7fffffff) //조건에 맞는 구간합이 없을 경우
		cout << 0;
	else
		cout << res;

	return 0;
}