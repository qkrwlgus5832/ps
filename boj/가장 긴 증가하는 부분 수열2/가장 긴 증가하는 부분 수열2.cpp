#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector <int> A;

vector <int> set_;

int main() {
	int N;
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
	set_.push_back(A[0]);  // 처음엔 비교 대상이 없으므로 넣어준다.

	for (int i = 0; i < N; i++) { // LIS 알고리즘 
		int maxvalue = set_.back();
		if (A[i] > maxvalue) {
			set_.push_back(A[i]);
		}
		else {
			auto iter = lower_bound(set_.begin(), set_.end(), A[i]); // lower_bound로 수정시킬 원소를 찾은 후 
			set_[iter - set_.begin()] = A[i]; // 수정시킨다.
		}

	}
	cout << set_.size();
	//system("Pause");
}