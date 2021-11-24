#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) { 

		vector<int> row;

		for (int j = 0; j < arr1[0].size(); j++) { // A의 i번쨰 행
			row.push_back(arr1[i][j]);
		}

		vector<int> retRow;

		for (int c = 0; c < arr2[0].size(); c++) { // B 열

			int tmp = 0;
			for (int r = 0; r < arr2.size(); r++) {
				tmp += row[r] * arr2[r][c];
			}

			retRow.push_back(tmp);
		}

		answer.push_back(retRow);

	}
	
	return answer;
}