#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

int main() {
	
	while (1) {
		int num;

		cin >> num;

		if (num == -1) break;
		
		vector<int> arr;

		for (int i = 1; i < num; i++) {
			if (num%i == 0)
				arr.push_back(i);
		}

		if (accumulate(arr.begin(), arr.end(), 0) == num) {

			cout << num << " =";

			for (int i = 0; i < arr.size(); i++) {
				cout << " " << arr[i];
				if (i == arr.size() - 1) break;
				cout<< " +";
			}
			cout << endl;

		}
		else {
			cout << num << " is NOT perfect." << endl;
		}

	}

	return 0;
}