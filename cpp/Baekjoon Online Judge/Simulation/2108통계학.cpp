#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> arr;
int minusVal[4001];
int plusVal[4001];

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	int num, sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr.push_back(num);
		sum += num;
	}

	sort(arr.begin(), arr.end());
	
	int maxValue = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0) {
			plusVal[arr[i]]++;
			maxValue = max(maxValue, plusVal[arr[i]]);
		}
		else {
			minusVal[-arr[i]]++;
			maxValue = max(maxValue, minusVal[-arr[i]]);
		}
	}

	vector<int> res;
	for (int i = 0; i <= 4000; i++) {
		if (plusVal[i] == maxValue)
			res.push_back(i);
		if (minusVal[i] == maxValue)
			res.push_back(-i);
	}


	double avg = (double)sum / n;
	
	printf("%.0f\n",avg);
	
	cout << (double)arr[n / 2] << endl;
	
	if(arr.size()==1)
		cout << res[0] << endl;
	else {
		if (res.size() > 1) {
			sort(res.begin(), res.end());
			cout << res[1] << endl;
		}
		else
			cout << res[0] << endl;
	}

	cout << abs(arr[0] - arr[n - 1]);

	return 0;
}