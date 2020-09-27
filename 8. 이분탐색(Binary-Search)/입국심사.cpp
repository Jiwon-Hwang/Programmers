#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long time_num = times.size();
    sort(times.begin(), times.end());

    long long min_time = 1;
    long long max_time = (long long)times.back() * (long long)n; // ��� long long����!

    long long mid_time = 0;
    while (min_time <= max_time) { //���� �������� �ݺ�
        long long person_num = 0;
        mid_time = (min_time + max_time) / 2;

        for (int i = 0; i < time_num; i++) {
            person_num += mid_time / times[i];
        }

        if (person_num < n) { // ������� �ð�
            min_time = mid_time + 1;
        }
        else {
            max_time = mid_time - 1; // ���� ��, ���� �ݺ��� min>max ��
            answer = mid_time;
        }
    }
    return answer;
}