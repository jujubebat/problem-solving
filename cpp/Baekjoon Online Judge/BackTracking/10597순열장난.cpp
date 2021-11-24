#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str;
vector<int> ret;
int maxNum;
bool check[50], flag;

void dfs(int index) {

	if (index == str.size()) {
		for (int tmp : ret)
			cout << tmp << " ";
		exit(0);
	}

	int num = stoi(str.substr(index, 1));

	if (num <= maxNum) { // 1개씩 자르는 경우
		if (!check[num]) { // 이미 순열에 포함된 수인지 체크한다. 
			check[num] = true;
			ret.push_back(num);
			dfs(index + 1); // 1개를 잘랐으므로 인덱스를 하나 증가시킨다.
			ret.pop_back();
			check[num] = false;
		}
	}
	
	num = stoi(str.substr(index, 2));

	if (num <= maxNum){ // 2개씩 자르는 경우 
		if (!check[num]) {
			check[num] = true;
			ret.push_back(num);
			dfs(index + 2); // 2개를 잘랐으므로 인덱스를 두 개 증가시킨다.
			ret.pop_back();
			check[num] = false;
		}
	}

}

int main() {
	cin >> str;

	maxNum = (str.size() - 9) / 2 + 9;
	
	dfs(0);
	return 0;
}