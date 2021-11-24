/***************
date : 20/02/01
design time : 20 min
implementation time : 15 min
debugging time : 30 min
****************/

//L개의 알파벳 소문자
//최소 한개의 모음, 최소 두 개의 자음, 오름차순정렬
//문자의 종류는 c가지 
//가능성 있는 암호를 모두 구하기.
//순열 //!! 조합이었음
//모음 : a, e, i, o, u
//a t c i s w
//1 5 2 3 4 6

//순열, dfs
//다음에 들어올 알파벳은 이전 알파벳 보다 커야함
//출력하기 전에 최소 조건 만족여부를 확인해야함(전역변수로 체크)
//가지치기 조건 : 오름차순 조건 위배시, 최소조건 만족 위배시 

//n개에서 m개를 뽑는 순열을 구현하되 암호의 조건을 맞춰야함
//최대 15개에서 15개를 뽑는 경우가 있음, 이경우 시간 복잡도가 매우클 것으로 예상
//따라서 가지치기를 잘해야함. 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int l, c;
vector<char> res;
char arr[15]; //후보 알파벳
bool visited[15];

void dfs() {
	if (res.size() == l) {//암호가 완성되면 출력
		//최소 조건 만족여부 확인(여기서 하면 시간복잡도 초과 우려됨)
		int a = 0, b = 0;
		for (char i : res) {
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
				a++;
			}
			else {
				b++;
			}
		}

		if (a < 1 || b < 2) return;

		for (char i : res) {
			printf("%c", i);
		}
		puts("");
		return;
	}

	//순열에 조건을 추가하여 푼다고생각했는데, 이것은 곧 조합이었음..
	for (int i = 0; i < c; i++) {
		if (!visited[i]) {
			if (!res.empty()) {
				if (res.back() < arr[i]) { //현재 벡터의 마지막 원소보다 크다면
					visited[i] = true;
					res.push_back(arr[i]);
					dfs();
					res.pop_back();
					visited[i] = false;
				}
			}
			else {
				visited[i] = true;
				res.push_back(arr[i]);
				dfs();
				res.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d", &l, &c);
	getchar();

	for (int i = 0; i < c; i++) {
		scanf("%c", &arr[i]);
		getchar();
	}

	sort(arr, arr + c);
	dfs();

	return 0;
}