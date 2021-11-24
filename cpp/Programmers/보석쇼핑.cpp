#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer; 
	answer.push_back(0);
	answer.push_back(0); // 정답 리턴을 위한 초기화

	// set을 사용하여 보석의 종류수를 센다.
	unordered_set<string> s; 
	
	for (auto tmp : gems) {
		s.insert(tmp);
	}

	int kind = s.size(); 

	// map을 사용하여 구간내 보석의 빈도수를 센다.
	unordered_map<string, int> m;
	int start = 0, end = 0;
	int minDist = 0x7fffffff;

	// 투포인터 기법을 사용해 연속된 구간들을 탐색해본다.
	while (1) {
		if (m.size() >= kind) { // 현재 구간이 조건에 맞는다면(모든 종류의 보석을 포함한다면)
			m[gems[start]]--; // 구간을 줄여본다.(맨 앞의 보석을 제거한다.)
			if (m[gems[start]] == 0)
				m.erase(gems[start]);
			start++;
		} 
		else if (end == gems.size()) // 현재 구간이 조건에 맞지않고, 마지막 포인터가 범위를 초과하면
			break; // 구간 탐색을 중지한다.
		else { // 현재 구간이 조건에 맞지 않는다면, 마지막 포인터를 증가시켜본다.(맨 뒤에 보석을 추가한다.)
			m[gems[end]]++;
			end++;
		}

		if (m.size() == kind) { // 현재 구간이 조건에 맞는지 확인한다.(모든 종류 보석 포함여부)
			if (abs(end - start) < minDist) { // 조건을 만족하는 최소 구간을 구한다.
				minDist = abs(end - start);
				answer[0] = start + 1;
				answer[1] = end;
			}
		}
	}

	return answer;
}


int main() {
	vector<string> input;
	input.push_back("ZZZ");
	input.push_back("YYY");
	input.push_back("NNNN");
	input.push_back("YYY");
	input.push_back("BBB");


	solution(input);

	return 0;
}