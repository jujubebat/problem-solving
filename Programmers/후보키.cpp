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

bool isUnique(vector<int> colums) { //유일성 검사함수
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

void combination2(int cnt) { // 후보키를 이루는 속성들의 부분 집합을 찾는함수

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

bool isMinimum() { //최소성 검사함수
	retFlag = 0;
	combination2(0);
	if (retFlag == 0)
		return true;
	else if (retFlag > 0)
		return false;
}

void combination(int cnt) { // 후보키 부분 집합을 찾는 함수

	if (v.size() > 0) {
		if (isUnique(v) && isMinimum()) { // 유일성 만족하는지 검사한다.
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

	//비트 마스킹으로 후보키가 될 수 있는 모든 부분 집합을 찾음
	for (int bit = 1; bit < (1 << columCount); bit++) {

		set<string> s;

		for (int i = 0; i < rowCount; i++) {
			string tmp = "";
			for (int j = 0; j < columCount; j++) {
				if ( bit&(1 << j) ) //만들어진 부분집합에 속성이 속한다면
					tmp += relation[i][j];
			}
			s.insert(tmp);
		}

		// 원소에 중복이 있는지 검사, 
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