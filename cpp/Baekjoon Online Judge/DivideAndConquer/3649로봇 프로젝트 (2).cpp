#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int arr[1000000];
int x, n;
vector<int> v;
int ret = -1;


// idx번째 블록과 합쳤을때 길이가 x가 되는 블록을 이분탐색으로 찾는다.
void find(int idx) {
	int low = 0, high = n;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		int size = arr[idx] + arr[mid]; // 두 블록을 합쳤을 경우.

		if (size >= x) {
			if (size == x && idx != mid) { // 두 블록의 합이 x이고, 중복된 블록 선택이 아닐때.
				if (abs(arr[idx] - arr[mid]) > ret) { 
					ret = abs(arr[idx] - arr[mid]);
					v.clear();
					v.push_back(idx);
					v.push_back(mid);
				}
			}
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> x) {

		// 매 테스트 케이스마다 값 초기화.
		memset(arr, 0, sizeof(arr));
		v.clear();
		ret = -1;

		x *= 10000000; // 나노 단위로 맞춰준다.

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n); // 이분탐색을 위해 정렬한다.

		for (int i = 0; i < n; i++) { // i번째 블록과 다른 블록 조합을 찾아본다.
			find(i);
		}

		if (v.empty()) // 결과가 없을 경우.
			cout << "danger" << endl;
		else { // 결과가 있을 경우, 오름차순으로 출력한다. 
			sort(v.begin(), v.end());
			cout << "yes " << arr[v[0]] << " " << arr[v[1]] << endl;
		}
	}

	return 0;
}
