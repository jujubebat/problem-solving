#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
	int res = 50;
	string a;
	string b;

	cin >> a >> b;
    
	int a_length = a.length();
	int b_length = b.length();

	for (int i = 0; i <= b_length - a_length; i++) {
		int cnt = 0;
		for (int j = 0; j < a_length; j++) {
			if (a[j] != b[j + i])
				cnt++;
		}
		res = min(res, cnt);
	}
	cout << res;
    return 0;
}
