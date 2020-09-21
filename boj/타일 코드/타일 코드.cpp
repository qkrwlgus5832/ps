#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


int N;

long long DP[31];

int main() {
	cin >> N;


	DP[1] = 1;
	DP[2] = 3;

	if (N == 1 || N == 2) {
		cout << DP[N];
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] * 2;
	}

	long long  symmetryCount = 0;

	if (N % 2 == 1) {
		if ((N - 1) >= 1)
			symmetryCount = DP[(N - 1) / 2];
	}

	if (N % 2 == 0) {
		if (N / 2 >= 1) {
			symmetryCount += DP[N / 2];
		}
		if ((N - 2) / 2 >= 1) {
			symmetryCount += DP[(N - 2) / 2] * 2;
		}
	}


	long long overlapCount = DP[N] - symmetryCount;
	cout << symmetryCount + overlapCount / 2;
	//ystem("Pause");
}

