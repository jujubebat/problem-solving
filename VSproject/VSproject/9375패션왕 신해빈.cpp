#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		map<string, int> clothMap;
		int n;
		cin >> n;
		int res = 1;

		while (n--) {
			string name, kind;
			cin >> name >> kind;
			clothMap[kind]++;
		}
		
		for (map<string, int>::iterator it = clothMap.begin(); it != clothMap.end(); it++) {
			res *= it->second+1;
		}

		cout << res -1 << endl;

	}
}