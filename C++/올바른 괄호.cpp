#include <string>
#include <iostream>
//#include <stack> => 스택은 벡터로 구현하는게 더 접근 쉬움!
#include <vector>

using namespace std;

bool solution(string s)
{
	if (s[0] == ')') return false;

	vector<char> stack; // string 아니고 char (문자 기호)
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			stack.push_back(s[i]);
			continue;
		}
		if (!stack.empty()) { // "())" 의 경우.. (빈 stack에서 pop하면 error)
			stack.pop_back();
			continue;
		}
		return false;
	}

	return stack.empty(); // 삼항연산자 안써도 됨!
}