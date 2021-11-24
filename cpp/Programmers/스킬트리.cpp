#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	set<char> s;

	for (int i = 0; i < skill.size(); i++) {
		s.insert(skill[i]); // ��ųƮ�� ��� ����.
	}

	for (int i = 0; i < skill_trees.size(); i++) {
		int idx = 0;
		bool flag = true;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			if (s.count(skill_trees[i][j]) == 0) continue; // ��ų Ʈ���� �ƴϸ�, ��ŵ

			if (skill[idx++] != skill_trees[i][j]) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer++;
	}

	return answer;
}