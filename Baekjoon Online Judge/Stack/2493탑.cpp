#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<pair<int, int>> st;
	int h;

	for (int i = 1; i <= n; i++) {
		cin >> h;
		while (!st.empty() && st.top().second < h)
			st.pop();
		if (st.empty())
			cout << 0 << ' ';
		else
			cout << st.top().first << ' ';
		st.push({ i,h });
	}

	return 0;
}



	
