#include<iostream>	
#include<queue>
using namespace std;

int main() {
	int x, y;
	priority_queue<double> pq;

	cin >> x >> y;
	pq.push(-x * ((double)1000 / y));

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		double a;
		double b;
		cin >> a >> b;
		pq.push(-a * ((double)1000 / b));
	}

	cout << fixed;
	cout.precision(2);
	cout << -pq.top();

	return 0;
}