#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
pair<int, int> leftHand, rightHand;

unordered_map<int, pair<int, int>> numberInfo;

char pressButton(int num, string hand) {
	
	bool L = false, R = false;

	if (num == 1
		|| num == 4
		|| num == 7) { // 왼쪽 열

		leftHand.first = numberInfo[num].first;
		leftHand.second = numberInfo[num].second;

		L = true;
	}
	else if (num == 2
		|| num == 5
		|| num == 8
		|| num == 0) { // 가운데 열

		int tx = numberInfo[num].first, ty = numberInfo[num].second;
		int leftDist = abs(leftHand.first - tx) + abs(leftHand.second - ty);
		int rightDist = abs(rightHand.first - tx) + abs(rightHand.second - ty);

		if (leftDist < rightDist) {
			leftHand.first = tx;
			leftHand.second = ty;
			L = true;
		}
		else if (rightDist < leftDist) {
			rightHand.first = tx;
			rightHand.second = ty;
			R = true;
		}
		else if (leftDist == rightDist) {
			if (hand == "left") {
				leftHand.first = tx;
				leftHand.second = ty;
				L = true;
			}
			else {
				rightHand.first = tx;
				rightHand.second = ty;
				R = true;
			}
		}

	}
	else if (num == 3
		|| num == 6
		|| num == 9) { // 오른쪽 열

		rightHand.first = numberInfo[num].first;
		rightHand.second = numberInfo[num].second;

		R = true;
	}

	if (L)
		return 'L';
	else if (R)
		return 'R';
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	
	numberInfo[1] = { 0,0 };
	numberInfo[2] = { 0,1 };
	numberInfo[3] = { 0,2 };
	numberInfo[4] = { 1,0 };
	numberInfo[5] = { 1,1 };
	numberInfo[6] = { 1,2 };
	numberInfo[7] = { 2,0 };
	numberInfo[8] = { 2,1 };
	numberInfo[9] = { 2,2 };
	//numberInfo['*'] = { 3,0 };
	numberInfo[0] = { 3,1 };
	//numberInfo['#'] = { 3,2 };

	leftHand.first = 3;
	leftHand.second = 0;

	rightHand.first = 3;
	rightHand.second = 2;

	for (int num : numbers) {
		answer += pressButton(num, hand);
	}

	return answer;
}