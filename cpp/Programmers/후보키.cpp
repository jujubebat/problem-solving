/*#include <string>
#include <vector>
#include<iostream>
#include<set>
using namespace std;

vector<vector<string>> g_relation;
vector<int> v;
vector<int> v2;
int columCount;
int ret = 0;
int retFlag;

bool isUnique(vector<int> colums) { //���ϼ� �˻��Լ�
	bool check[10] = { false };

	for (int k : colums) {
		check[k] = true;
	}

	bool flag = true;
	set<string> s;

	for (int i = 0; i < g_relation.size(); i++) {
		string tmp = "";
		for (int j = 0; j < g_relation[i].size(); j++) {
			if (!check[j]) continue;
			tmp += g_relation[i][j];
		}

		if (s.count(tmp) == 1) {
			flag = false;
		}
		s.insert(tmp);
	}

	return flag;
}

void combination2(int cnt) { // �ĺ�Ű�� �̷�� �Ӽ����� �κ� ������ ã���Լ�

	if (v2.size() == v.size()) return;

	if (v2.size() > 0) {
		if (isUnique(v2)) retFlag++;
	}

	for (int i = cnt; i < v.size(); i++) {
		v2.push_back(v[i]);
		combination2(i + 1);
		v2.pop_back();
	}

}

bool isMinimum() { //�ּҼ� �˻��Լ�
	retFlag = 0;
	combination2(0);
	if (retFlag == 0)
		return true;
	else if (retFlag > 0)
		return false;
}

void combination(int cnt) { // �ĺ�Ű �κ� ������ ã�� �Լ�

	if (v.size() > 0) {
		if (isUnique(v) && isMinimum()) { // ���ϼ� �����ϴ��� �˻��Ѵ�.
			ret++;
		}
	}

	if (v.size() == columCount) return;

	for (int i = cnt; i < columCount; i++) {
		v.push_back(i);
		combination(i + 1);
		v.pop_back();
	}
}

int solution(vector<vector<string>> relation) {

	g_relation = relation;
	columCount = relation[0].size();
	combination(0);

	return ret;
}
*/

/*#include <string>
#include <vector>
#include<iostream>
#include<set>
using namespace std;

bool isMininum(vector<int> &ret, int bit) {
	for (int i = 0; i < ret.size(); i++) {
		if ((ret[i] & bit) == ret[i])
			return false;
	}
	return true;
}

int solution(vector<vector<string>> relation) {

	int rowCount = relation.size();
	int columCount = relation[0].size();
	vector<int> ret;

	//��Ʈ ����ŷ���� �ĺ�Ű�� �� �� �ִ� ��� �κ� ������ ã��
	for (int bit = 1; bit < (1 << columCount); bit++) {

		set<string> s;

		for (int i = 0; i < rowCount; i++) {
			string tmp = "";
			for (int j = 0; j < columCount; j++) {
				if ( bit&(1 << j) ) //������� �κ����տ� �Ӽ��� ���Ѵٸ�
					tmp += relation[i][j];
			}
			s.insert(tmp);
		}

		// ���ҿ� �ߺ��� �ִ��� �˻�, 
		if (s.size() == rowCount && isMininum(ret, bit))
			ret.push_back(bit);
	}

	return ret.size();
}*/

#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<bitset>
using namespace std;

int main() {
	for (int bit = 1; bit < (1 << 4); bit++) {
		cout << bitset<8>(bit) << endl;
	}
	return 0;
}