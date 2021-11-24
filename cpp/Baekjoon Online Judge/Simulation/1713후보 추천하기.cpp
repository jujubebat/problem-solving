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

//ù ��° ���ڰ� �� ��° ���ں��� �տ� 
//�� ������ ��ȯ�ؾ� �ϴ� �� ���Ѿ� �մϴ�.
bool comp(photo a, photo b) {
	if (a.cnt == b.cnt) {
		return a.postTime < b.postTime; // �ð��� �����ȼ�
	}else
		return a.cnt < b.cnt; // ��õ�� ������
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

		// ������ �ɸ� ������ ��õ�ϴ� ���
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

		//if (flag) cout << "����" << endl;

		if (!flag) { //���Ӱ� �߰��Ǵ� �����ϰ��.
			if (arr.size() < n) { // ����ִ� ����Ʋ�� �ִ°��.
				arr.push_back({ recommend , 1, time });
			}
			else { // ����ִ� ����Ʋ�� ���� ���
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