#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> p;

int main() {
	int n;
	
	cin >> n;

	priority_queue< p, vector<p>, greater<p> > pq;

	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		
		if (x == 0) {
			if (pq.empty())
				printf("0\n");
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(x), x));
		}
	}

	return 0;
}