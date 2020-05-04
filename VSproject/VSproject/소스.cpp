#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> arr1(5); // 원소 5개를 만들고 0으로 초기화한다. 

	for (int i = 0; i < arr1.size(); i++) {
		cout << arr1[i];
	}

	cout << endl;
	cout << endl;

	vector<int> arr2(7, 7);

	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i];
	}

	cout << endl;
	cout << endl;

	vector<vector<string>> arr3(5, vector<string>(4, "abcd")); // 복잡한 vector 초기화

	for (int i = 0; i < arr3.size(); i++) {
		for (int j = 0; j < arr3[i].size(); j++) {
			cout << arr3[i][j][0] <<" " << arr3[i][j][1] << " " << arr3[i][j][2] << " " << arr3[i][j][3] << endl;
		}
		cout << endl;
	}

	return 0;
}