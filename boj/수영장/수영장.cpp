#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int result = INT_MAX;

int calculate(bool check[12], int dp[12], int threemonthcost) {
	int value = 0;
	for (int i = 0; i < 12;) {
		if (check[i] == true) {
			value += threemonthcost;
			i += 3;
		}
		else {
			value += dp[i];
			i++;
		}
	}
	return value;
}

void recursion(int index, int dp[12],  bool check[12], int threemonthcost) {
	result = min(result, calculate(check,dp,  threemonthcost));

	for (int i = index; i < 10; i++) {
		check[i] = true;
		recursion(i + 3, dp, check, threemonthcost);
		check[i] = false;
	}

}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int cost[4];
		int input[12];
		int dp[12];
		result = INT_MAX;

		for (int i = 0; i < 4; i++) {
			scanf("%d", &cost[i]);
		}
		for (int i = 0; i < 12; i++) {
			scanf("%d", &input[i]);
			dp[i] = min(input[i] * cost[0], cost[1]);
		}

		bool check[12] = { false, };
		recursion(0, dp, check, cost[2]);
		printf("#%d %d\n", t, min(result, cost[3]));
	}
	//system("Pause");

}