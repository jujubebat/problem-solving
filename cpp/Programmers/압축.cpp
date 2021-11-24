#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> m;

	for (int i = 0; i <= 25; i++) {
		string tmp = "";
		tmp += 'A' + i;
		m[tmp] = i+1;
	}
	
	int index = 27;
	string input = "";
	
	for (int i = 0; i < msg.size(); i++) {
		
		input += msg[i];

		if (i < msg.size() - 1 && m.count(input+msg[i+1])) {
			continue;
		}

		string tmp = "";

		// �������� ���� �Է°� ��ġ�ϴ� ���� �乮�ڿ��� ã�´�.
		if (m.count(input)) { 
			answer.push_back(m[input]); // w�� �ش��ϴ� ������ ���� ��ȣ�� ���.
			tmp = input;
			input = ""; // �Է¿��� w�� �����Ѵ�. 
		}

		if (i < msg.size() - 1) {
			m[tmp + msg[i + 1]] = index++;
		}
		
	}

	return answer;
}