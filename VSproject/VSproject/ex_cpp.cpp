#include<iostream>
#include<string>

using namespace std;

int main() {
	string s = "hello world!";
	string s2 = "HELLO world!";

	printf("s size = %d\n", s.size());

	string w = s.substr(0, 5);

	cout << w << endl;

	s.replace(0, 5, "HELLO");

	cout << s << endl;

	if (s.compare(s2) == 0)
		cout << "s1, s2 same";

	return 0;
}