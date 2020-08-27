#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {

	int ret = 0x7fffffff;
	sort(dist.begin(), dist.end());

	for (int i = 0; i < weak.size(); i++) {

		int back = weak[0] + n;
		weak.erase(weak.begin());
		weak.push_back(back);

		do {
			int w = 0;
			int d = 0;

			for (d = 0; d < dist.size(); d++) {

				int range = weak[w] + dist[d];

				while (range >= weak[w]) {
					w++;
					if (w == weak.size()) {
						ret = min(ret, d + 1);
						break;
					}
				}
				if (w == weak.size()) {
					break;
				}
			}


		} while (next_permutation(dist.begin(), dist.end()));
	}

	if (ret == 0x7fffffff)
		return -1;
	else
		return ret;
}