#include<iostream>
#include<string>
using namespace std;

int main() {
	string a, b;
	char op;

	cin >> a;
	cin >> op;
	cin >> b;
	
	if (op == '*') {
		cout << 1;
		string sum = a + b;
		for (int i = 0; i < sum.size(); i++)
			if (sum[i] == '0')
				cout << 0;
	}
	else if (op == '+'){
		if (a.size() == b.size()) {
			cout << 2;
			for (int i = 0; i < a.size(); i++)
				if (a[i] == '0')
					cout << 0;
		}
		else {
			if (b.size() > a.size()) swap(a, b);
			for (int i = 0; i < a.size() - b.size(); i++) {
				cout << a[i];
			}
			cout << b;
		}
		
	}

	return 0;
}