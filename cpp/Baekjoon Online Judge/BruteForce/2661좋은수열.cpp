/*
----설계----
1.숫자를 하나씩 추가한다.
2.추가한 경우 나쁜 순열인지 검사한다.
  -새롭게 추가한 맨뒷자리 숫자부터 하나씩 증가시키며 비교.
3.n자리의 좋은 수열을 만들면 출력하고 종료한다. 

---상세구현 설계 ---

dfs로 탐색하기, 나쁜 순열일 경우 가지치키
1,2,3 순서로 탐색함으로 가장 처음 만들어지는 수열 출력.
*/

//내 풀이
/*
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
int flag = false;

bool isBad() {
	int size = v.size() / 2;

	for (int i = 1; i <= size; i++) {
		int last_idx = v.size() - 1;
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (v[last_idx] == v[last_idx - i])
				cnt++;
			last_idx--;
		}
		if (cnt == i)
			return true;
	}

	return false;
}

void dfs() {
	if (isBad())
		return;

	if (n == v.size()) {
		for (int x : v) {
			printf("%d", x);
		}
		flag = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
		dfs();
		if (flag)
			return;
		v.pop_back();
	}
}

int main() {
	cin >> n;
	dfs();
	return 0;
}

*/
#include <iostream>
#include <string>
using namespace std;

int n;
bool flag;

void dfs(string str) {
	if (flag) return;

	int len = str.length();
	for (int i = 1; i <= len / 2; i++) {
		if (str.substr(len - i, i) == str.substr(len - 2 * i, i)) {
			str = "";
			return;
		}
	}

	if (str.length() == n) {
		flag = true;
		cout << str << '\n';
		return;
	}
	
	dfs(str + '1');
	dfs(str + '2');
	dfs(str + '3');
}
int main() {
	cin >> n;
	dfs("");
	return 0;
}