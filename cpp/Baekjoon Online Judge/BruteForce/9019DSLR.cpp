#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef struct {
	int num;
	string str;
}regis;

int start, dest;

string bfs() {
	queue<regis> q;
	bool check[10001] = { false };
	
	check[start] = true;
	q.push({ start,"" });

	while (!q.empty())
	{
		int num = q.front().num;
		string str = q.front().str;
		q.pop();
		if (num == dest)
			return str;

		int d[4] = { 2 * num % 10000, num - 1, num%1000 * 10 + num/1000,  (num%10)*1000+ num/10};
		int c[4] = { 'D','S','L','R' };

		if (d[1] < 0) 
			d[1] = 9999;

		for (int i = 0; i < 4; i++) {
			int newNum = d[i];
			string newStr = str;
			newStr += c[i];
			if (check[newNum]) continue;
			check[newNum] = true;
			q.push({ newNum,newStr });
		}
	}
}

void solve() {
	string res = bfs();
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> start >> dest;
		solve();
	}
	return 0;
}