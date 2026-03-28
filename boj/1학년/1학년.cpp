#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> input;

long long dp[101][21];

int main() {
	cin >> N;
	input.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}

	dp[0][input[0]] = 1;

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + input[i + 1] <= 20)
				dp[i + 1][j + input[i + 1]] += dp[i][j];
			if (j - input[i + 1] >= 0)
				dp[i + 1][j - input[i + 1]] += dp[i][j];
		}
	}

	cout << dp[N - 2][input[input.size() - 1]];
	//system("Pause");
}
