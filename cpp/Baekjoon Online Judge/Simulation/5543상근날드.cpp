#include<iostream>
#include<queue>
using namespace std;

int main() {

	int arr[3];

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	priority_queue<int> pq;

	for (int i = 0; i < 2; i++) {
		int num; 
		cin >> num;
		for (int j = 0; j < 3; j++) {
			pq.push(-1 * (num + arr[j]-50));
		}
	}

	cout << -pq.top(); 

	return 0;
}