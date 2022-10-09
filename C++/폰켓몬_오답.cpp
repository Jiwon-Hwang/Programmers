#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // next_permutation(����), ����
using namespace std;

// ���� (�ð��ʰ�)
int solution(vector<int> nums)
{
	int N = nums.size();
	int max_num = 0;

	// 0, 1�� �־� �ӽ� ����(combination) ���� => nCk
	vector<int> tmpVec;
	for (int i = 0; i<N / 2; i++) {
		tmpVec.push_back(1); // k����ŭ 1�ֱ�
	}
	for (int j = 0; j<N / 2; j++) {
		tmpVec.push_back(0); // n-k����ŭ 0�ֱ�
	}

	sort(tmpVec.begin(), tmpVec.end()); // ����

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