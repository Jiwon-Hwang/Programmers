#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

// sol1) map(dict), isdigit, substr 이용
int solution1(string s) {
	map<string, string> m;
	m["zero"] = "0";
	m["one"] = "1";
	m["two"] = "2";
	m["three"] = "3";
	m["four"] = "4";
	m["five"] = "5";
	m["six"] = "6";
	m["seven"] = "7";
	m["eight"] = "8";
	m["nine"] = "9";

	int idx = 0;
	string result = "";
	while (idx < s.size()) {
		if (isdigit(s[idx])) {
			result += s[idx];
			idx++;
			continue;
		}
		for (int i = 3; i < 6; i++) { // key는 3~5글자 (ex. "three")
		// cf. contains는 c++20부터.. / find : 키 값이 있는지 없는지
			if (m.count(s.substr(idx, i))) { // idx로부터 i개 slice
				result += m[s.substr(idx, i)];
				idx += i;
				break;
			}
		}
	}

	return stoi(result);
}

// sol2) regex (REGular EXpression 이용)
int solution2(string s) {
	//s.replace(s.find("zero"), 4, "0"); // 이건 find 해서 없을 경우 error...

	s = regex_replace(s, regex("zero"), "0"); // s에서 "zero"를 "0"으로 replace한 결과 s를 return
	s = regex_replace(s, regex("one"), "1");
	s = regex_replace(s, regex("two"), "2");
	s = regex_replace(s, regex("three"), "3");
	s = regex_replace(s, regex("four"), "4");
	s = regex_replace(s, regex("five"), "5");
	s = regex_replace(s, regex("six"), "6");
	s = regex_replace(s, regex("seven"), "7");
	s = regex_replace(s, regex("eight"), "8");
	s = regex_replace(s, regex("nine"), "9");

	return stoi(s);
}