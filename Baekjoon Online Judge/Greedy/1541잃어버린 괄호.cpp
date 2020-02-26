#include<iostream>
#include<string>

using namespace std;

int main() {
	int result = 0;
	string temp = "";
	bool minus = false;
	string str;

	cin >> str;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == NULL) {
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);

			temp = "";

			if (str[i] == '-') minus = true;
			continue;
		}
		temp += str[i];
	}

	printf("%d", result);
	
	return 0;
}