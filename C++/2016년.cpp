#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
	vector<int> days = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	vector<string> date = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	/*
	int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	string date[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
	*/

	int tmp = -1;
	for (int i = 0; i<a - 1; i++) {
		tmp += days[i];
	}
	tmp += b;

	return date[tmp % 7];
}