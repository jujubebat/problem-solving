#include<iostream>
#include<stack>
using namespace std;

int map[100][100];
int n, m, r;

void operation(int op) {

	if (op == 1) {

		stack<int> st;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				st.push(map[i][j]);
			}

			for (int i = 0; i < n; i++) {
				map[i][j] = st.top();
				st.pop();
			}
		}

	}
	else if (op == 2) {

		stack<int> st;
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				st.push(map[i][j]);
			}

			for (int j = 0; j < m; j++) {
				map[i][j] = st.top();
				st.pop();
			}
		}

	}
	else if (op == 3) {
		int tmp[100][100];
		copy(&map[0][0], &map[n - 1][m - 1] + 1, &tmp[0][0]);

		stack<int> st;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				st.push(tmp[i][j]);
			}

			for (int i = 0; i < n; i++) {
				map[j][i] = st.top();
				st.pop();
			}
		}

		swap(n, m);

	}
	else if (op == 4) {

		int tmp[100][100];
		copy(&map[0][0], &map[n - 1][m - 1] + 1, &tmp[0][0]);

		stack<int> st;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				st.push(tmp[i][j]);
			}

			for (int j = 0; j < m; j++) {
				map[j][i] = st.top();
				st.pop();
			}
		}

		swap(n, m);

	}
	else if (op == 5) {

		int tmp[100][100];
		copy(&map[0][0], &map[n - 1][m - 1] + 1, &tmp[0][0]);
		int a = n / 2, b = m / 2;
		// 1번을 2번으로 
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				map[i][j+b] = tmp[i][j];
			}
		}
		// 2번을 3번으로 
		for (int i = 0; i < a; i++) {
			for (int j = b; j < b+b; j++) {
				map[i+a][j] = tmp[i][j];
			}
		}
		// 3번을 4번으로 
		for (int i = a; i < a+a; i++) {
			for (int j = b; j < b+b; j++) {
				map[i][j - b] = tmp[i][j];
			}
		}
		// 4번을 1번으로
		for (int i = a; i < a+a; i++) {
			for (int j = 0; j < b; j++) {
				map[i-a][j] = tmp[i][j];
			}
		}

	}
	else if (op == 6) {

		int tmp[100][100];
		copy(&map[0][0], &map[n - 1][m - 1] + 1, &tmp[0][0]);
		int a = n / 2, b = m / 2;

		// 1번을 4번으로 
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				map[i+a][j] = tmp[i][j];
			}
		}
		// 4번을 3번으로 
		for (int i = a; i < a+a; i++) {
			for (int j = 0; j < b; j++) {
				map[i][j+b] = tmp[i][j];
			}
		}
		// 3번을 2번으로 
		for (int i = a; i < a + a; i++) {
			for (int j = b; j < b + b; j++) {
				map[i-a][j] = tmp[i][j];
			}
		}
		// 2번을 1번으로
		for (int i = 0; i < a; i++) {
			for (int j = b; j < b+b; j++) {
				map[i][j-b] = tmp[i][j];
			}
		}
	}
}

int main() {

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int op;
	for (int i = 0; i < r; i++) {
		cin >> op;
		operation(op);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}