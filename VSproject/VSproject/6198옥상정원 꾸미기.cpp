
//맨위는 건물번호, 맨위 아래 원소들은 맨위 건물을 볼 수 있는 건물들.
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 1e5 * 8;

int buildings[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i];
	}

	stack<int> s;

	long long result = 0;

	for (int i = 0; i < N; i++)
	{
		while (s.empty() == false && s.top() <= buildings[i])
		{
			s.pop();
		}

		s.push(buildings[i]);
		cout<< s.size() - 1 <<endl;
		result += s.size() - 1;
	}

	cout << result << "\n";

	return 0;
}
