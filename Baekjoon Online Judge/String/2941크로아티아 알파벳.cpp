#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {
	set<string> s;

	s.insert("c=");
	s.insert("c-");
	s.insert("dz=");
	s.insert("d-");
	s.insert("lj");
	s.insert("nj");
	s.insert("s=");
	s.insert("z=");

	string str;
	cin >> str;

	int res = 0;
	int size = str.size();

	for (int i = 0; i < size; i++) {
		string tmp = "";
		if (i + 1 < size) {
			for (int j = i; j < i + 2; j++) {
				tmp += str[j];
			}
			
			if (s.count(tmp)) {
				res++;
				i += 1;
				continue;
			}
		}
		
		if (i + 2 < size) {
			tmp = "";
			for (int j = i; j < i + 3; j++) {
				tmp += str[j];
			}

			if (s.count(tmp)) {
				i += 2;
				res++;
				continue;
			}
		}

		res++;
	}

	cout << res;
	return 0; 
}