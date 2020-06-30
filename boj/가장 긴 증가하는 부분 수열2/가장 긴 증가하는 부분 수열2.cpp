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
	set_.push_back(A[0]);  // ó���� �� ����� �����Ƿ� �־��ش�.

	for (int i = 0; i < N; i++) { // LIS �˰��� 
		int maxvalue = set_.back();
		if (A[i] > maxvalue) {
			set_.push_back(A[i]);
		}
		else {
			auto iter = lower_bound(set_.begin(), set_.end(), A[i]); // lower_bound�� ������ų ���Ҹ� ã�� �� 
			set_[iter - set_.begin()] = A[i]; // ������Ų��.
		}

	}
	cout << set_.size();
	//system("Pause");
}