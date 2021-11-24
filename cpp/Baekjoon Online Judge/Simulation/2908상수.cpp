#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main() {
	string a,b;
	int aNum = 0, bNum = 0;

	cin >> a >> b;
	
	for (int i = 0; i <3; i++) {
		aNum += (a[i] - '0')*pow(10, i);
		bNum += (b[i] - '0')*pow(10, i);
	}

	if (aNum > bNum)
		cout << aNum;
	else
		cout << bNum;
	return 0;
}