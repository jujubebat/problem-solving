#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}

	return answer;
}

// a, b 배열은 길이가 같음.
// 하나씩 뽑아야함. 뽑은 숫자는 뽑을 수 없음.
// 모든 경우의 수를 고려해야함.
// 조합?

// a 넥퍼뮤 돌리고, 각 경우에대해서 b 넥퍼뮤돌려서 순차대로 계산하여 
// 결과 계산 

// a 오름 차순, b 내림 차순 정렬