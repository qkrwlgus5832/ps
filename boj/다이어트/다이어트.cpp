#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

vector <long long> A;
set <long long> result;

void twoPointer(int G) {
	int start = 0;
	int end = 0;

	while (1) {
		if (start > end || (start == A.size() - 1 && end == A.size() - 1))
			break;

		long long tmp = A[end] - A[start];

		if (tmp == G) {
			result.insert(sqrt(A[end]));
		}
		if (tmp <= G && end < A.size() - 1) {
			end++;
		}
		else if (start < A.size() -1){
			start++;
		}
		else if (end == A.size() - 1) {
			start++;
		}
	}
}


int main() {
	int G;
	cin >> G;

	for (int i = 1; i <= 100000; i++) {
		A.push_back(pow(i, 2));
	}
	twoPointer(G);

	if (result.size() == 0) {
		cout << -1;
	}
	else {
		for (auto iter = result.begin(); iter != result.end(); iter++) {
			printf("%d\n", *iter);
		}
	}
	//system("Pause");
}