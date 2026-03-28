#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector <int> A;

int N, M;

int result = INT_MAX;

void twoPointer() {
	int start = 0;
	int end = 0;

	while (1) {
		if (start > end || (start == A.size() - 1 && end == A.size() - 1))
			break;

		int tmp = A[end] - A[start];
		
		if (tmp >= M)
			result = min(result, tmp);

		if (tmp >= M && start  < A.size() -1) {
			start++;
		}
		else if (end < A.size() -1){
			end++;
		}
		else if (end == A.size() - 1) {
			start++;
		}
	}

}
int main() {
	cin >> N >> M;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	sort(A.begin(), A.end());
	twoPointer();
	cout << result;
	//system("Pause");

}