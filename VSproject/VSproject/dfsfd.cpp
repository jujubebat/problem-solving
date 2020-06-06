#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int arr[18] = { 10,8,6,6,6,1,2,2,8,6,4,5,10,6,8,7,1,9 };

	do {
		for (int i = 0; i < 18; i++)
			cout << arr[i];
		cout << endl;
	} while (next_permutation(arr, arr + 18));

	return 0; 

}