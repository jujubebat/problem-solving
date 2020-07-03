#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int num;
	int cnt;
	int postTime;
}photo;

vector<photo> arr;

//첫 번째 인자가 두 번째 인자보다 앞에 
//올 조건을 반환해야 하는 건 지켜야 합니다.
bool comp(photo a, photo b) {
	if (a.cnt == b.cnt) {
		return a.postTime < b.postTime; // 시간이 오래된순
	}else
		return a.cnt < b.cnt; // 추천이 적은순
}

int main() {
	int n;
	cin >> n;

	int recommendCnt;
	cin >> recommendCnt;

	int time = 0;

	while (recommendCnt--) {
		time++;

		int recommend;
		cin >> recommend;

		bool flag = false;

		// 기존에 걸린 사진에 추천하는 경우
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i].num == recommend) {
				arr[i].cnt++;

				//cout << " arr[i].num : " << arr[i].num << endl;
				//for (auto tmp : arr)
					//cout << tmp.num << " " << tmp.cnt << " " << tmp.postTime << endl;

				flag = true; 
				break;
			}
		}

		//if (flag) cout << "뭐지" << endl;

		if (!flag) { //새롭게 추가되는 사진일경우.
			if (arr.size() < n) { // 비어있는 사진틀이 있는경우.
				arr.push_back({ recommend , 1, time });
			}
			else { // 비어있는 사진틀이 없는 경우
				sort(arr.begin(), arr.end(), comp);

				//for (auto tmp : arr)
					//cout << tmp.num << " " << tmp.cnt << " " << tmp.postTime << endl;
				//cout << endl;
				arr.erase(arr.begin());
				arr.push_back({ recommend , 1, time });
			}
		}
	}

	vector<int> ret;
	for (photo tmp : arr) {
		ret.push_back(tmp.num);
	}

	sort(ret.begin(), ret.end());

	for (int tmp : ret)
		cout << tmp << " ";

	return 0;
}