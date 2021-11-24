#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<set>
using namespace std;

typedef struct {
	long long num;
	string str;
}number;

int start, dest;
int limit = 1000000000;
set<long long> check;

void bfs() {
	queue<number> q;
	q.push({ start, "" });

	while (!q.empty()){
		long long num = q.front().num;
		string str = q.front().str;
		q.pop();

		if (num == dest) {
			cout << str;
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (i == 0) {//*
				if (num*num >=1 && num*num <= limit && check.count(num*num)==0) {
					check.insert(num*num);
					q.push({ num*num, str + '*' });
				}
			}
			else if (i == 1) {//+
				if (num+num >= 1 && num + num <= limit && check.count(num + num) == 0) {
					check.insert(num + num);
					q.push({ num + num, str + '+' });
				}
			}
			else if (i == 2) {//-
				if (num - num >= 1 && num - num <= limit && check.count(num - num) == 0) {
					check.insert(num - num);
					q.push({ num - num, str + '/' });
				}
			}
			else if (i == 3 && num > 0) {// /
				if (num / num >= 1 && num / num <= limit && check.count(num / num) == 0) {
					check.insert(num / num);
					q.push({ num / num, str + '/' });
				}
			}
		}
	}

    cout << -1;
	return;
}

int main() {
	cin >> start >> dest;
	if (start == dest)
		cout << 0;
	else
		bfs();
	
	
	return 0;
}