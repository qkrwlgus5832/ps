#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int dp[5001];


int main() {
	int T;
	cin >> T;

	dp[1] = 1;

	for (int i = 2; i <= 2500; i++) {
		for (int j = 1; j < i; j++) {
			long long sum1 = 0;
			if (j == 1)
				sum1++;
			else
				sum1 = dp[j - 1];
			
			sum1 = (sum1 * dp[i - j]) % 1000000007;

			dp[i] = (dp[i] + sum1) % 1000000007;
		}
		dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
	}

	int input;
	for (int i = 0; i < T; i++) {
		scanf("%d", &input);
		if (input % 2 != 0)
			printf("%d\n", 0);
		else
			printf("%d\n", dp[input / 2]);
	}

	//system("Pause");
}
