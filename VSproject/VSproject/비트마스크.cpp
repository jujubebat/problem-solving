#include<iostream>
#include<bitset>
using namespace std;

int main() {
	puts("[비트 조작 기본]\n");
	cout << "정수 6을 32bit로 출력 : " << bitset<32>(6) << endl;
	cout << "정수 4를 32bit로 출력 : " << bitset<32>(4) << endl;
	cout << "6과 4의 and 연산 : " << bitset<32>(6 & 4) << endl;
	cout << "6을 오른쪽으로 1번 shfit : "<< bitset<32>(6 >> 1) << endl;
	cout << "4을 왼쪽으로 2번 shfit : "<<bitset<32>(4 << 2) << endl;

	puts("\n[20가지 토핑이 있는 피자집 예제] : 비트마스크를 통해 토핑 조합을 구할 수 있다.\n");

	puts("1.공 집합 구하기(토핑을 하나도 안 고르는 경우)");
	int pizza = 0;
	cout << bitset<32>(pizza) << "\n\n";

	puts("2.꽉찬 집합 구하기(토핑을 20가지 다 고르는 경우)");
	pizza = (1 << 20) - 1;
	cout << bitset<32>(pizza) << "\n\n";

	puts("3.피자에 7번 토핑 추가하기");
	int p = 7;
	pizza = 0;
	pizza |= (1 << p); 
	cout << bitset<32>(pizza) << "\n\n";

	puts("4.피자에 7번 토핑이 포함돼있는지 확인하기");
	if (pizza & (1 << p)) cout << "7번 토핑 포함되어 있습니다.\n\n";
	
	puts("5.피자에 7번 토핑 삭제하기");
	pizza &= ~(1 << p);
	cout << bitset<32>(pizza) << "\n\n";

	puts("6.4가지 종류의 토핑이 있을 때, 피자를 만드는 경우의 수");
	pizza= 15;
	for (int subset = pizza; subset; subset -=1 ) {
		cout << bitset<32>(subset) << " : " << subset << endl;
	}

	return 0;
}