#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

vector<string> g_user_id;
vector<string> g_banned_id;
int banned_id_sameNum[10];
int answer = 0;
bool visited[10];
bool check[10][10][10];
set<vector<string>> s;

vector<string> v;

bool Comp(string a, string b) {
	return a < b;
}

void dfs() {

	if (v.size() == g_banned_id.size()) {

		bool flag = true;
		for (int i = 0; i < g_banned_id.size(); i++) {
			if (v[i].size() != g_banned_id[i].size())
				return;

			int num = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == g_banned_id[i][j]) //문자가 같다면.
					num++;
			}
			if (num != banned_id_sameNum[i]) flag = false;
		}

		vector<string> arr;
		for (string str : v) {
			arr.push_back(str);
		}

		sort(arr.begin(), arr.end());

		if (flag) {
			if (s.count(arr) == 1) {
				flag = false;
			}
			else if (s.count(arr) == 0) {
				s.insert(arr);
				answer++;
			}
		}

		return;
	}

	for (int i = 0; i < g_user_id.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(g_user_id[i]);
			dfs();
			v.pop_back();
			visited[i] = false;

		}

	}
}

int solution(vector<string> user_id, vector<string> banned_id) {

	g_user_id = user_id;
	g_banned_id = banned_id;

	for (int i = 0; i < banned_id.size(); i++) {
		int num = 0;
		for (int j = 0; j < banned_id[i].size(); j++) {
			if (banned_id[i][j] != '*')
				num++;
		}
		banned_id_sameNum[i] = num;
	}

	dfs();


	return answer;
}