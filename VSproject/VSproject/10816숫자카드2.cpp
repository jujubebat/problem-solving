#include<iostream>
#include<map>
using namespace std;

map<int, int> cardMap;

int main() {
	int n, m;

	cin >> n;

	int num;
	while (n--) {
		scanf_s("%d", &num); 
		cardMap[num]++;
	}

	cin >> m;
	while (m--) {
		scanf_s("%d", &num);
		int res = cardMap.find(num)->second;

		if (res)
			printf("%d ", res);
		else
			printf("0 ");
	}
	
	return 0;
}