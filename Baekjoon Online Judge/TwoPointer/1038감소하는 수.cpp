#include<iostream>
#include<queue>
using namespace std;

queue<long long> q;
long long arr[1000001]; //n의 최대값은 1000000이다, long long 자료형을 사용한다.

int main() {
	
	for (int i = 0; i <= 9; i++) //0~9까지 큐에 넣어준다.
		q.push(i);

	int idx = 0; //배열 순차접근을 위한 인덱스

	while (!q.empty()) { 
		long long num = q.front(); //큐에서 원소를 하나씩 꺼내서,
		arr[idx++] = num; //배열에 순차적으로 넣는다.
		if (idx > 1000000) break; //idx(n)이 1000000보다 크면 종료
		q.pop();

		//큐에서 꺼낸 수에서 이어지는 감소하는 수를 만들어 큐에 넣어준다.
		for (int i = 0; i < 10; i++) { 
			if (num % 10 > i) { //현재 1의 자리수보다 작은 수만 골라서,
				long long tmp = num * 10 + i; //감소하는 수를 만든다.
				q.push(tmp);
			}
		}
	}

	//감소하는 수는 1023번째부터는 존재하지 않는다. (1022번째 감소하는 수는 9,876,543,210 이다.)

	int n;
	cin >> n;
	if (n > 1022) 
		cout << -1;
	else
		cout << arr[n]; //n번째 감소하는 수를 출력한다.

	return 0;
}
