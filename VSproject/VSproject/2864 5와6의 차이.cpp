#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string a, b;
	int minRes = 1e9;
	int maxRes = -1e9;

	cin >> a >> b;

	for (int i = 0; i < 2; i++) {
		string tmpA = a, tmpB = b;
		if (i == 0) {// 둘다5
			for (int j = 0; j < a.size(); j++) {
				if (tmpA[j] == '6')
					tmpA[j] = '5';
			}

			for (int j = 0; j < b.size(); j++) {
				if (tmpB[j] == '6')
					tmpB[j] = '5';
				minRes = stoi(tmpA) + stoi(tmpB);
			}
		}
		else if (i == 1) { //둘다 6
			for (int j = 0; j < a.size(); j++) {
				if (tmpA[j] == '5')
					tmpA[j] = '6';
			}

			for (int j = 0; j < b.size(); j++) {
				if (tmpB[j] == '5')
					tmpB[j] = '6';
				maxRes = stoi(tmpA) + stoi(tmpB);
			}
		}
	}

	cout << minRes << " "<< maxRes;

	return 0;
}