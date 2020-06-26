#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	for (auto num1 : phone_book) {
		for (auto num2 : phone_book) {
			if (num1.compare(num2) == 0) continue;
			if(num1.size() > num2.size()) continue;
			if (num1.compare(num2.substr(0, num1.size())) == 0) {
				return false;
			}
		}
	}
	return true;
}