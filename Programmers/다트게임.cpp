/*
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
	int answer = 0;

	for (int i = 0; i < dartResult.size(); i++) {

		if (i > 0 && isdigit(dartResult[i]) ) {
			if (dartResult[i - 1] == 'S'
				|| dartResult[i - 1] == 'D'
				|| dartResult[i - 1] == 'T'
				|| dartResult[i - 1] == '#'
				|| dartResult[i - 1] == '*') {
				dartResult.insert(i, 1, ',');
			}
		}

	}

	int cnt = 0;
	string chance[3] = { "" };

	for (int i = 0; i < dartResult.size(); i++) {

		if (dartResult[i] == ',') {
			cnt++;
			continue;
		}

		if (cnt == 0) {
			chance[0] += dartResult[i];
		}
		else if (cnt == 1) {
			chance[1] += dartResult[i];
		}
		else if (cnt == 2) {
			chance[2] += dartResult[i];
		}

	}

	int scores[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		string scoreStr;
		char bonus = NULL;
		char option = NULL;

		for (int j = 0; j < chance[i].size(); j++) {
			if (isdigit(chance[i][j]))
				scoreStr += chance[i][j];

			if (chance[i][j] == 'S')
				bonus = 'S';
			else if (chance[i][j] == 'D')
				bonus = 'D';
			else if (chance[i][j] == 'T')
				bonus = 'T';
			else if (chance[i][j] == '*')
				option = '*';
			else if (chance[i][j] == '#')
				option = '#';

		}

		int scoreNum = stoi(scoreStr);

		if (bonus == 'S') {
			scores[i] = scoreNum;
		}
		else if (bonus == 'D') {
			scores[i] = pow(scoreNum, 2);
		}
		else if (bonus == 'T') {
			scores[i] = pow(scoreNum, 3);
		}

		if (option == '*') {
			scores[i] *= 2;
			if (i > 0) {
				scores[i - 1] *= 2;
			}
		}
		else if (option == '#') {
			scores[i] *= -1;
		}

	}

	return scores[0] + scores[1] + scores[2];
} */

#include<string>
#include<vector>
#include<cmath>
using namespace std;

int solution(string dartResult) {
	vector<int> scoreList;
	int score = 0;

	for (int i = 0; i < dartResult.size(); i++) {

		if (isdigit(dartResult[i])) {
			score = score * 10 + dartResult[i] - '0';
		}
		else if (dartResult[i] == 'S') scoreList.push_back(score), score = 0;
		else if (dartResult[i] == 'D') scoreList.push_back(pow(score, 2)), score = 0;
		else if (dartResult[i] == 'T') scoreList.push_back(pow(score, 3)), score = 0;
		else if (dartResult[i] == '*') {

			scoreList.back() *= 2;
			if (scoreList.size() > 1) 
				*(scoreList.end() - 2) *= 2;
				
		}
		else if (dartResult[i] == '#') {
			scoreList.back() *= -1;
		}

	}

	return scoreList[0] + scoreList[1] + scoreList[2];
}