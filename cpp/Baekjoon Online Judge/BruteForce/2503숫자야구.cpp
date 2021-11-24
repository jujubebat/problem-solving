#include<iostream>
#include<string>
using namespace std;

typedef struct {
	int num, s, b;
}question;

int b = 0;
int main() {
	int n;
	question arr[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].num >> arr[i].s >> arr[i].b;
	}
	int res = 0;
	for (int i = 111; i <= 999; i++) {
		string a = to_string(i);
		if (a[0] == '0' || a[1] == '0' || a[2] == '0') continue;
		if (a[0] == a[1]) continue;
		if (a[1] == a[2]) continue;
		if (a[2] == a[0]) continue;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			int sCnt = 0, bCnt = 0;
			string b = to_string(arr[j].num);
			
			//스트라이크 검사 
			for (int k = 0; k < 3; k++) {
				if (a[k] == b[k])
					sCnt++;
			}
			if (arr[j].s != sCnt) {
				flag = false;
				break;
			}
			
			//볼검사 
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (a[k] == b[l] && k != l) {
						bCnt++;
					}
				}
			}
			if (arr[j].b != bCnt) {
				flag = false;
				break;
			}
		}
		if (flag) res++;//참이면 res++;
	}
	cout << res;
}