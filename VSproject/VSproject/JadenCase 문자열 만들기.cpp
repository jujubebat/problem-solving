#include <string>
#include <vector>

using namespace std;

string solution(string s) {

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ' && !isdigit(s[i])) {
			s[i] = tolower(s[i]);
		}
	}

	if (!isdigit(s[0])) {
		s[0] = toupper(s[0]);
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			s[i + 1] = toupper(s[i + 1]);
		}
	}

	return s;
}