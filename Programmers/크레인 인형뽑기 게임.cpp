#include <string>
#include <stack>
#include <vector>

using namespace std;

int catch_doll(vector<vector<int>> &board, int col) {
	for (int i = 0; i < board.size(); i++) {
		if (board[i][col] != 0) {
			int num = board[i][col];
			board[i][col] = 0;
			return num;
		}
	}
	return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int ans = 0;
	stack<int> st;

	for (int i = 0; i < moves.size(); i++) {
		int num = catch_doll(board, moves[i] - 1);

		printf("num %d\n", num);

		if (num != 0) {
			if (!st.empty())
				printf("st top %d\n", st.top());

			if (st.empty())
				st.push(num);
			else if (!st.empty()) {
				if (st.top() == num) {
					st.pop();
					ans++;
				}
				else {
					st.push(num);
				}
			}
		}
	}
	return ans * 2;
}