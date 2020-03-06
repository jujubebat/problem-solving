/*#include<iostream>
using namespace std;

int weights[30];
int beads[7];
bool d[15001];
int n, k;

void solve(int cnt, int beadWeight) {
	if (cnt > n) return;
	if (d[beadWeight]) return;

	d[beadWeight] = true;
	d[beads[cnt + 1]] = true;

	solve(cnt+1, beadWeight);//case1
	solve(cnt + 1, beadWeight + beads[cnt]);//case2
	solve(cnt + 1, abs(beadWeight - beads[cnt]));
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> beads[i];
	}

	solve(0,0);

	for (int i = 0; i < k; i++) {
	
			if (d[beads[i]])
				printf("Y ");
			else
				printf("N ");
	}

	return 0;
}*/

#include <iostream>

#include <cstring> //memset

#include <algorithm>

using namespace std;



const int MAX = 30;



int weightNum, marbleNum; //추 개수, 구슬 개수

int weight[MAX]; //추

int marble[7]; //구슬

int cache[MAX + 1][MAX * 500 + 1]; //추의 갯수, 추의 갯수로 만들 수 있는 무게



void preCalculate(int currentWeightNum, int currentWeight) //현재 추의 갯수, 현재 만들어 낸 무게

{

	//기저 사례

	if (currentWeightNum > weightNum)

		return;



	int &result = cache[currentWeightNum][currentWeight];

	if (result != -1)

		return;



	cache[currentWeightNum][currentWeight] = 1; //현재 만들어진 무게 기록



	//가능한 추의 갯수를 증가하고 해당 추를 구슬이 없는 저울에 올릴 경우

	preCalculate(currentWeightNum + 1, currentWeight + weight[currentWeightNum]);

	//가능한 추의 갯수를 증가하지만 해당 추를 어느 저울에도 올리지 않을 경우

	preCalculate(currentWeightNum + 1, currentWeight);

	//가능한 추의 갯수를 증가하고 해당 추를 구슬 쪽에 있는 저울에 올릴 경우

	preCalculate(currentWeightNum + 1, abs(currentWeight - weight[currentWeightNum]));

}



int main(void)

{

	cin >> weightNum;

	for (int i = 0; i < weightNum; i++)

		cin >> weight[i];



	cin >> marbleNum;

	for (int i = 0; i < marbleNum; i++)

		cin >> marble[i];



	memset(cache, -1, sizeof(cache));

	preCalculate(0, 0); //모든 가능한 경우를 연산



	for (int i = 0; i < marbleNum; i++)

	{

		if (marble[i] > MAX * 500) //500g 추 30개를 추가한 것보다 무거운 구슬이라면

			cout << "N ";

		else if (cache[weightNum][marble[i]] == 1)

			cout << "Y ";

		else

			cout << "N ";

	}


	for (int i = 0; i < weightNum; i++) {
		for (int j = 0; j < marbleNum; j++) {
			printf("%d %d %d\n", i,j,cache[weightNum][marble[j]]);
		}
	}

	cout << endl;

	return 0;



}

