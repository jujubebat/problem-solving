#include<iostream>
#include<vector>
using namespace std;

vector<int> primes;
bool isPrime[4000001] = { false };
int n;

int solve() {

	int cnt = 0, sum = 0;
	int low = 0, high = 0;

	// 투포인터 기법을 사용해 만족하는 구간을 O(N)만에 찾는다. 
	// 범위를 넘어서는 인덱스 접근을 막기 위해 high 값에 상한을 둔다.
	while(low <= high && high < primes.size()-1){ 
		if (sum >= n) {
			if (sum == n) cnt++;
			sum -= primes[low++];
		}
		else if (sum < n) {
			sum += primes[high++];
		}
	}

	return cnt;
}

int main() {

	// 주어진 최대값 이하에서 소수집합(primes)을 만든다. 
	for (int i = 2; i <= 4000000; i++) {
		if (isPrime[i]) continue;
		primes.push_back(i);
		for (int j = 2; i*j <= 4000000; j++) {
			isPrime[i*j] = true;
		}
	}

	cin >> n;
	cout << solve();
	
	return 0;
}