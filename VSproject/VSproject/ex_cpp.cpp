#include<iostream>
#include<set>
using namespace std;

int main() {
	int map[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j];
		}
		puts("");
	}

}