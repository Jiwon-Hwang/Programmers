#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 시간초과! (정확성 정답, 효율성 오답)
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
	//bool arr[1000001] = {true}; // 이렇게 하면 첫번째 값만 true로 초기화됨! (나머지는 false)
	//arr[0] = arr[1] = false; // 0과 1은 소수 x

	// 배열 초기화 (sol1)
	/*
	bool arr[1000001];
	for(int i = 2; i <= n; i++){
		arr[i] = true;
	}
	*/

	// 배열 초기화 (sol2)
	vector<bool> arr(n + 1, true); // 동적으로 벡터 크기 및 초기값 지정 : vec(size, value) => 조금 더 느림

								   // 에라토스테네스의 체 => 배수들(소수가 아닌 애들)을 0으로 바꿔줌
	for (int i = 2; i <= int(sqrt(n)); i++) {
		if (arr[i] == true) {
			for (int j = i + i; j <= n; j += i) { // i(소수)의 배수 싹다 false로 바꿔주기 (소수빼고 다)
				arr[j] = false;
			}
		}
	}

	// 소수의 개수 계산
	for (int i = 2; i <= n; i++) {
		if (arr[i] == true) cnt += 1;
	}

	return cnt;
}