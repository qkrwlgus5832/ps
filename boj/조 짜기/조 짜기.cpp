#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


vector <int> v;
int dp[1001];

int main() {
	int N;
	cin >> N;

	v.resize(N + 1);

	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		v[i] = input;
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int maxValue = -1;
			int minValue = INT_MAX;

			for (int i1 = j; i1 <= i; i1++) {
				maxValue = max(maxValue, v[i1]);
				minValue = min(minValue, v[i1]);
			}
			dp[i] = max(dp[i], dp[j - 1] + maxValue - minValue);
		}
	}

	cout << dp[N];
	//system("Pause");
}