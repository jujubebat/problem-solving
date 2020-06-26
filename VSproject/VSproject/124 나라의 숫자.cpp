#include <string>
#include <vector>
using namespace std;

string solution(int n) {
	string answer = "";

	while (n != 0) {
		answer = "412"[n % 3] + answer;
		if (n % 3 == 0) n--;
		n /= 3;
	}

	return answer;
}