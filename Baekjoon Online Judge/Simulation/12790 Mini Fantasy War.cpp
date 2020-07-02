#include<iostream>
using namespace std;

int main() {
	int t; 

	cin >> t;

	while (t--) {
		int baseHP, baseMP, baseAttack, baseDefence;
		cin >> baseHP >> baseMP >> baseAttack >> baseDefence;

		int equipHP, equipMP, equipAttack, euipDefence;
		cin >> equipHP >> equipMP >> equipAttack >> euipDefence;

		baseHP += equipHP; if (baseHP < 1) baseHP = 1;
		baseMP += equipMP; if (baseMP < 1) baseMP = 1;
		baseAttack += equipAttack; if (baseAttack < 0) baseAttack = 0;
		baseDefence += euipDefence;

		cout << (1 * baseHP) + (5 * baseMP) + (2 * baseAttack) + (2 * baseDefence) << endl;
	}

	return 0;
}