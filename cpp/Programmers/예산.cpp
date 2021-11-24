#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int low = 0, high = 1000000000;
	long long sum = 0;
	int ret = -1;

	for (int tmp : budgets) {
		sum += tmp;
		ret = max(ret, tmp);
	}

	if (sum <= M)
		return ret;

	while (low <= high) {
		int mid = (low + high) / 2;
		long long sum = 0;
	
		for (int budget : budgets) {
			if (budget > mid)
				sum += mid;
			else
				sum += budget;
		}

		if (sum <=  M) { 
			answer = max(answer, mid);
			low = mid + 1;
		}
		else { 
			high = mid - 1; 
		}
	}

	return answer;
}