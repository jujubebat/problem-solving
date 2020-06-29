#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	set<int> s;
	int answer = 0;

	for (int i = 0; i < nums.size(); i++) {
		s.insert(nums[i]);
	}

	if (s.size() >= nums.size() / 2) {
		return nums.size() / 2;
	}
	else
		return s.size();
}