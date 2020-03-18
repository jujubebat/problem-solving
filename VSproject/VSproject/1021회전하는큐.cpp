#include<iostream>
#include<queue>
using namespace std;

bool check[51];
queue<int> arr;
deque<int> dq;

int res = 0;

int main() {
	int n, m;

	deque<int> ::iterator it;

	cin >> n >> m;

	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		arr.push(num);
	}

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int left = 0, right = 0, index = 1;
	while (!arr.empty())
	{
		if (dq.front() == arr.front()) {
			dq.pop_front();
			arr.pop();
		}
		else {
			index = 1;
			for (deque<int>::iterator it = dq.begin(); it < dq.end(); it++) {
				if (*it == arr.front()) break;
				index++;
			}
			left = index - 1, right = dq.size() - index + 1;

			if (left <= right) {
				while (dq.front() != arr.front()) {
					dq.push_back(dq.front());
					dq.pop_front();
					res++;
				}
				dq.pop_front();
				arr.pop();
			}
			else if (right < left) {
				while (dq.front() != arr.front()) {
					dq.push_front(dq.back());
					dq.pop_back();
					res++;
				}
				dq.pop_front();
				arr.pop();
			}
		}
	}

	cout << res;
	return 0;
}#include<iostream>
#include<queue>
using namespace std;

bool check[51];
queue<int> arr;
deque<int> dq;

int res = 0;

int main() {
	int n, m;

	deque<int> ::iterator it;

	cin >> n >> m;

	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		arr.push(num);
	}

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int left = 0, right = 0, index = 1;
	while (!arr.empty())
	{
		if (dq.front() == arr.front()) {
			dq.pop_front();
			arr.pop();
		}
		else {
			index = 1;
			for (deque<int>::iterator it = dq.begin(); it < dq.end(); it++) {
				if (*it == arr.front()) break;
				index++;
			}
			left = index - 1, right = dq.size() - index + 1;

			if (left <= right) {
				while (dq.front() != arr.front()) {
					dq.push_back(dq.front());
					dq.pop_front();
					res++;
				}
				dq.pop_front();
				arr.pop();
			}
			else if (right < left) {
				while (dq.front() != arr.front()) {
					dq.push_front(dq.back());
					dq.pop_back();
					res++;
				}
				dq.pop_front();
				arr.pop();
			}
		}
	}

	cout << res;
	return 0;
}