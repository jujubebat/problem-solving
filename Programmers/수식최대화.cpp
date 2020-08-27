
/*
// [20/08/26]

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<char> operPriority;
set<char> s;

long long cal(vector<long long> numbers, vector<char> operations) {

	for (char operation : operPriority) {
		for (int i = 0; i < operations.size(); i++) {
			if (operations[i] == operation) {
				if (operation == '+') {
					numbers[i + 1] = numbers[i] + numbers[i + 1];
				}
				else if (operation == '-') {
					numbers[i + 1] = numbers[i] - numbers[i + 1];
				}
				else if (operation == '*') {
					numbers[i + 1] = numbers[i] * numbers[i + 1];
				}
				numbers.erase(numbers.begin() + i);
				operations.erase(operations.begin() + i);
				i--;
			}
		}
	}

	return abs(numbers[0]);
}

long long solution(string expression) {
	vector<long long> numbers;
	vector<char> operations;
	long long answer = 0;

	string tmp = "";
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+'
			|| expression[i] == '-'
			|| expression[i] == '*') {
			if (!s.count(expression[i])) {
				s.insert(expression[i]);
				operPriority.push_back(expression[i]);
			}
			operations.push_back(expression[i]);
			numbers.push_back(stoi(tmp));
			tmp = "";
		}
		else
			tmp += expression[i];
	}

	numbers.push_back(stoi(tmp));
	sort(operPriority.begin(), operPriority.end());

	do {
		answer = max(answer, cal(numbers, operations));
	} while (next_permutation(operPriority.begin(), operPriority.end()));

	return answer;
}

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

long long cal(vector<long long> num , vector<char> oper, vector<char> operPirority) {

	// 주어진 연산자 우선순위 벡터의 연산자를 순차적으로 탐색한다.
	// (operPirority에 들어있는 연산자 순서가 우선순위 순서다.)
	for (char priority : operPirority) {
		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == priority) { // 연산자와 숫자가 들어있는 각 벡터를 탐색하며 계산한다.
				long long calResult;
				if (priority == '*') {
					calResult = num[i] * num[i + 1];
				}
				else if(priority == '+') {
					calResult = num[i] + num[i + 1];
				}
				else if (priority == '-') {
					calResult = num[i] - num[i + 1];
				}
				num[i] = calResult; 
				num.erase(num.begin() + i + 1);
				oper.erase(oper.begin() + i);
				i--;
			}
		}
	}
	
	return abs(num[0]); // 절대값을 리턴한다. 
}

long long solution(string expression) {

	long long answer = 0;
	vector<char> oper; // 연산자를 담는 벡터
	vector<long long> num; // 숫자를 담는 벡터
	vector<char> operPirority; // 연산자 우선순위를 담는 벡터
	
	string tmpNum = "";
	bool check[1000000];
	memset(check, false, sizeof(check));

	// 주어진 표현식에서 연산자와, 숫자를 추출한다.
	for (int i = 0; i < expression.size(); i++) {
		if (isdigit(expression[i])) { // 숫자 문자일 경우 tmpNum에 임시저장.
			tmpNum += expression[i];
		} else if (expression[i] == '+' // 연산자일경우
			|| expression[i] == '-' 
			|| expression[i] == '*') {

			// 표현식에 등장한 연산자를 한 번씩만 넣는다.
			// operPirority 벡터는 연산자 우선순위를 표현하는 용도이다.
			if (!check[expression[i]]) {
				check[expression[i]] = true;
				operPirority.push_back(expression[i]); 
			}

			oper.push_back(expression[i]); // 연산자 벡터에 넣는다.
			num.push_back(stoi(tmpNum)); // tmpNum을 숫자로 바꿔서 숫자 벡터에 넣는다.
			tmpNum = ""; // 다음 숫자를 담기위해 tmpNum 초기화
		}
	}

	num.push_back(stoi(tmpNum)); // 마지막 숫자를 넣는다.

	// operPirority에 들어있는 연산자들에 대하여 순열을 구한다.
	// 모든 순열을 구한다는 것 == 모든 우선순위 조합을 구한다는 것.
	sort(operPirority.begin(), operPirority.end()); 

	do {
		// 숫자를 담은 벡터, 연산자를 담은 벡터, 
		// next_permutation으로 구한 연산자 우선순위가 들어있는 벡터를
		// cal 함수의 인자로 넣어주고 수식 계산을한다. 
		// 계산의 결과에 대해 최대값 여부를 확인하고 갱신한다. 
		answer = max(answer, cal(num, oper, operPirority));
	} while (next_permutation(operPirority.begin(), operPirority.end()));

	return answer;
}