#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;

int ret = 0;
vector<int> v;
string s;
bool visited[10];
set<int> st;

bool isPrime(int num) {
	if (num == 1 || num == 0) return false;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}

	return true;
}

void permutation() {

	if (v.size() > 0) {
		int num = 0;
		for (int k : v)
			num = num * 10 + k;

		if (isPrime(num)) {
			if (st.count(num) == 0) {
				st.insert(num);
				ret++;
			}
		}

	}

	if (v.size() == s.size())
		return;

	for (int i = 0; i < s.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(s[i] - '0');
			permutation();
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;

	cin >> c;

	for (int i = 0; i < c; i++) {
		st.clear();
		memset(visited, false, sizeof(visited));
		v.clear();
		cin >> s;
		ret = 0;
		permutation();
		cout << ret << endl;
	}

	return 0;
}