#include<iostream>
#include<vector>
using namespace std;

vector<int> primes;
bool isPrime[4000001] = { false };
int n;

int solve() {

	int cnt = 0, sum = 0;
	int low = 0, high = 0;

	// �������� ����� ����� �����ϴ� ������ O(N)���� ã�´�. 
	// ������ �Ѿ�� �ε��� ������ ���� ���� high ���� ������ �д�.
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

	// �־��� �ִ밪 ���Ͽ��� �Ҽ�����(primes)�� �����. 
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