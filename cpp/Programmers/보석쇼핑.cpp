#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer; 
	answer.push_back(0);
	answer.push_back(0); // ���� ������ ���� �ʱ�ȭ

	// set�� ����Ͽ� ������ �������� ����.
	unordered_set<string> s; 
	
	for (auto tmp : gems) {
		s.insert(tmp);
	}

	int kind = s.size(); 

	// map�� ����Ͽ� ������ ������ �󵵼��� ����.
	unordered_map<string, int> m;
	int start = 0, end = 0;
	int minDist = 0x7fffffff;

	// �������� ����� ����� ���ӵ� �������� Ž���غ���.
	while (1) {
		if (m.size() >= kind) { // ���� ������ ���ǿ� �´´ٸ�(��� ������ ������ �����Ѵٸ�)
			m[gems[start]]--; // ������ �ٿ�����.(�� ���� ������ �����Ѵ�.)
			if (m[gems[start]] == 0)
				m.erase(gems[start]);
			start++;
		} 
		else if (end == gems.size()) // ���� ������ ���ǿ� �����ʰ�, ������ �����Ͱ� ������ �ʰ��ϸ�
			break; // ���� Ž���� �����Ѵ�.
		else { // ���� ������ ���ǿ� ���� �ʴ´ٸ�, ������ �����͸� �������Ѻ���.(�� �ڿ� ������ �߰��Ѵ�.)
			m[gems[end]]++;
			end++;
		}

		if (m.size() == kind) { // ���� ������ ���ǿ� �´��� Ȯ���Ѵ�.(��� ���� ���� ���Կ���)
			if (abs(end - start) < minDist) { // ������ �����ϴ� �ּ� ������ ���Ѵ�.
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