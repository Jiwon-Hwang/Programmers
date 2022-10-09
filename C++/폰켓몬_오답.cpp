#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // next_permutation(순열), 조합
using namespace std;

// 오답 (시간초과)
int solution(vector<int> nums)
{
	int N = nums.size();
	int max_num = 0;

	// 0, 1을 넣어 임시 조합(combination) 생성 => nCk
	vector<int> tmpVec;
	for (int i = 0; i<N / 2; i++) {
		tmpVec.push_back(1); // k개만큼 1넣기
	}
	for (int j = 0; j<N / 2; j++) {
		tmpVec.push_back(0); // n-k개만큼 0넣기
	}

	sort(tmpVec.begin(), tmpVec.end()); // 정렬

	do {
		set<int> s;
		for (int i = 0; i < N; i++) { // N : tmpVec.size()
			if (tmpVec[i] == 1) {
				//cout << nums[i] << " ";
				s.insert(nums[i]);
			}
		}
		//cout << endl;
		max_num = max(max_num, int(s.size()));

	} while (next_permutation(tmpVec.begin(), tmpVec.end()));

	return max_num;
}