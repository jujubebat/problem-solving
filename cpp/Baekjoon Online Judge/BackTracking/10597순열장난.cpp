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

	if (num <= maxNum) { // 1���� �ڸ��� ���
		if (!check[num]) { // �̹� ������ ���Ե� ������ üũ�Ѵ�. 
			check[num] = true;
			ret.push_back(num);
			dfs(index + 1); // 1���� �߶����Ƿ� �ε����� �ϳ� ������Ų��.
			ret.pop_back();
			check[num] = false;
		}
	}
	
	num = stoi(str.substr(index, 2));

	if (num <= maxNum){ // 2���� �ڸ��� ��� 
		if (!check[num]) {
			check[num] = true;
			ret.push_back(num);
			dfs(index + 2); // 2���� �߶����Ƿ� �ε����� �� �� ������Ų��.
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