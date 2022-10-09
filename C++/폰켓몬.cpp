#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int N = nums.size();
	set<int> s(nums.begin(), nums.end());

	return N / 2 > s.size() ? s.size() : N / 2;
}