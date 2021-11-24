#include<iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	int n, b, h, w;

	cin >> n >> b >> h >> w;

	for (int i = 0; i < h; i++) {
		int p;
		cin >> p;
		
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;

			if (n <= a && p*n <= b)
				pq.push(-p*n);
		}
	}

	if (pq.empty() == 1)
		cout << "stay home";
	else
		cout << -pq.top();

	return 0;
}