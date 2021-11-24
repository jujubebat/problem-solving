#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int solution(int n) {
	int size = bitset<32>(n).count();

	for (int i = n+1; ; i++) {
		if (bitset<32>(i).count() == size)
			return i;
	}
}
