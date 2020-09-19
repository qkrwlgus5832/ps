#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


using namespace std;

int dp[500001];
vector <pair <int, int>> v;

int main() {
	int N;
	cin >> N;

	int A, B;



	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A, &B);
		v.push_back({ A,B });
	}

	sort(v.begin(), v.end(), [](const pair <int, int> &a, const pair <int, int> &b) {
		return a.second < b.second;
	});


	dp[N] = INT_MAX;

	for (int i = N - 1; i >= 0; i--) {
		dp[i] = min(v[i].first , dp[i + 1]);
	}

	long long sum = 0;

	int minDiffIndex = 0;
	int minDiff = INT_MAX;

	for (int i = 0; i < N; i++) {
		sum += v[i].second;

		if (v[i].first - v[i].second < minDiff) {
			minDiffIndex = i;
			minDiff = v[i].first - v[i].second;
		}

		long long result = INT_MAX;
		if (i + 1 < N)
			result = min(sum - v[minDiffIndex].second + v[minDiffIndex].first, sum - v[i].second + dp[i + 1]);
		else
			result = sum - v[minDiffIndex].second + v[minDiffIndex].first;

		printf("%lld\n", result);
	}
}