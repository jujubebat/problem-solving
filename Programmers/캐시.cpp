#include<algorithm>
#include <string>
#include<deque>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	if (cacheSize == 0) return cities.size() * 5; // 예외처리 : 캐시 size가 0일때 

	for (int i = 0; i < cities.size(); i++) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
	}

	deque<string> cache;

	for (int i = 0; i < cities.size(); i++) {
		bool flag = false;

		for (int j = 0; j < cache.size(); j++) {
			if (cities[i] == cache[j]) { // hit
				cache.erase(cache.begin() + j);
				answer += 1;
				cache.push_back(cities[i]);
				flag = true;
				break;
			}
		}

		if (!flag) { // miss
			answer += 5;
			if (cache.size() >= cacheSize) cache.pop_front();
			cache.push_back(cities[i]);
		}
	}

	return answer;
}
