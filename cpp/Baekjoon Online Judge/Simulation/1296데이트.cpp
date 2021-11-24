#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string man;
	int m_L = 0, m_O = 0, m_V = 0, m_E = 0;

	cin >> man;

	for (int i = 0; i < man.size(); i++) {
		if (man[i] == 'L') {
			m_L++;
		}
		else if (man[i] == 'O') {
			m_O++;
		}
		else if (man[i] == 'V') {
			m_V++;
		}
		else if (man[i] == 'E') {
			m_E++;
		}
	}

	int n;
	cin >> n;

	int maxScore = -1;
	string ret;

	while (n--) {
		string woman;
		int L = m_L, O = m_O, V = m_V, E = m_E;

		cin >> woman;

		for (int i = 0; i < woman.size(); i++) {
			if (woman[i] == 'L') {
				L++;
			}
			else if (woman[i] == 'O') {
				O++;
			}
			else if (woman[i] == 'V') {
				V++;
			}
			else if (woman[i] == 'E') {
				E++;
			}
		}

		int score = ((L + O)*(L + V)*(L + E)*(O + V)*(O + E)*(V + E)) % 100;

		if (score > maxScore) {
			maxScore = score;
			ret = woman;
		}else if (score == maxScore) {
			if(woman.compare(ret) < 0)
				ret = woman;
		}

	}

	cout << ret;
	return 0;
}