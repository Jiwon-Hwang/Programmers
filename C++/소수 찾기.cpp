#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* �ð��ʰ�! (��Ȯ�� ����, ȿ���� ����)
bool isPrime(int num){
	if(num == 2){
		return true;
	}
	for(int i = 2; i<=int(sqrt(num)); i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}
*/

int solution(int n) {
	int cnt = 0;
	//bool arr[1000001] = {true}; // �̷��� �ϸ� ù��° ���� true�� �ʱ�ȭ��! (�������� false)
	//arr[0] = arr[1] = false; // 0�� 1�� �Ҽ� x

	// �迭 �ʱ�ȭ (sol1)
	/*
	bool arr[1000001];
	for(int i = 2; i <= n; i++){
		arr[i] = true;
	}
	*/

	// �迭 �ʱ�ȭ (sol2)
	vector<bool> arr(n + 1, true); // �������� ���� ũ�� �� �ʱⰪ ���� : vec(size, value) => ���� �� ����

								   // �����佺�׳׽��� ü => �����(�Ҽ��� �ƴ� �ֵ�)�� 0���� �ٲ���
	for (int i = 2; i <= int(sqrt(n)); i++) {
		if (arr[i] == true) {
			for (int j = i + i; j <= n; j += i) { // i(�Ҽ�)�� ��� �ϴ� false�� �ٲ��ֱ� (�Ҽ����� ��)
				arr[j] = false;
			}
		}
	}

	// �Ҽ��� ���� ���
	for (int i = 2; i <= n; i++) {
		if (arr[i] == true) cnt += 1;
	}

	return cnt;
}