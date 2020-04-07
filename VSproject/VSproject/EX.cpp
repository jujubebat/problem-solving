#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, int> m;

	m.insert({ "박병욱", 26 });
	m.insert({ "김규식", 24 });
	m.insert({ "이기택", 28 });
	m.insert({ "이기택", 25 }); // map은 중복된 원소를 허락하지 않는다. 왼쪽 코드는 무시됨. 

	//아래와 같이 배열 형태로 원소를 추가할 수 있다.

	/*
	m["박병욱"] = 26;
	m["김규식"] = 24;
	m["이기택"] = 28;
	*/

	cout << m.count("박병욱") << endl;
	cout << m.count("김규식") << endl;
	cout << m.count("이기택") << endl;

	cout << m["박병욱"] << endl;
	cout << m["김규식"] << endl;
	cout << m["이기택"] << endl;

	//이터레이터를 통해 map을 아래와 같이 조회할 수 있다.
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}