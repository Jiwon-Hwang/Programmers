#include <string>
#include <iostream>
//#include <stack> => ������ ���ͷ� �����ϴ°� �� ���� ����!
#include <vector>

using namespace std;

bool solution(string s)
{
	if (s[0] == ')') return false;

	vector<char> stack; // string �ƴϰ� char (���� ��ȣ)
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			stack.push_back(s[i]);
			continue;
		}
		if (!stack.empty()) { // "())" �� ���.. (�� stack���� pop�ϸ� error)
			stack.pop_back();
			continue;
		}
		return false;
	}

	return stack.empty(); // ���׿����� �Ƚᵵ ��!
}