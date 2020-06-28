#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> arr;

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	int start = 0, end = 0;
	int sum = 0;

	while (1) {
		if (sum >= n)
			sum -= arr[start++];
		else if (end == n)
			break;
		else
			sum += arr[end++];

		if (sum == n) answer++;
	}

	return answer;
}

int main() {
	solution(15);
	return 0;
}