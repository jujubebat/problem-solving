#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
	int low = 1, high = 200000000;
	
	while (low <= high) {
		
		int mid = (low + high) / 2; // �ϴ��� ������
		vector<int> tmp = stones;

		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] - mid <= 0) 
				tmp[i] = 0;
		}

		bool flag = true;                       
		int cnt = 0;
		for (int i = 0; i < tmp.size(); i++) {

			if (tmp[i] == 0)
				cnt++;
			else {
				if (cnt >= k) {
					flag = false;
				}
				cnt = 0;
			}

			if (i == tmp.size() - 1) {
				if (cnt >= k) {
					flag = false;
				}
			}
		}

		if (flag) { //�ϴ�� �÷�����   
			low = mid + 1;
		}
		else { //�ϴ�� �ٿ�����
			high = mid - 1;                   
		}
	}

	return low;
}