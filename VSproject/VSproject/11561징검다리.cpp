#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int t; 

	cin >> t; 

	for (int i = 0; i < t; i++) {
		
		long long n;

		cin >> n;

		long long low = 1, high = n;
		long long ret = 1;

		while (low <= high) {
			long long mid = (low + high) / 2; // 점프거리 
			long long cnt = 1, curPos = mid;

			cout << low << " " << high << endl;

			while (curPos <= n) {
				if (curPos == n) {
					cnt = 0;
					break;
				}
				curPos += curPos + 1;
				cnt++;
				
			}

			if (cnt <= n) {
				ret = max(ret, cnt);
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		cout << ret <<endl;
	}

	return  0;
}