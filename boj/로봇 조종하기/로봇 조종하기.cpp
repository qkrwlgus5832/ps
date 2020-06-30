#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int graph[1001][1001];
int N, M;

int direction[3][2] = { { 1,0 }, { 0, -1 }, {0,1} };

int result = INT_MIN;
int DP[1001][1001][3];


int recursion(int i, int j, int value, int dir, bool check[1001][1001]) {
	if (i == N - 1 && j == M - 1) {
		return graph[i][j];
	}

	if (DP[i][j][dir] != INT_MIN) {
		return DP[i][j][dir];
	}

	int maxvalue = INT_MIN;

	bool flag = false;

	for (int i1 = 0; i1 < 3; i1++) {
		int ni = i + direction[i1][0];
		int nj = j + direction[i1][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			continue;

		if (check[ni][nj] == false) {
			check[ni][nj] = true;
			int currentValue = recursion(ni, nj, value, i1, check);
			maxvalue = max(maxvalue, currentValue);

			check[ni][nj] = false;
			flag = true;
		}
	}
	if (flag == true) {
		DP[i][j][dir] = maxvalue + graph[i][j];
		return DP[i][j][dir];
	}
	else {
		return -1000000000;
	}
}

int main() {


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			DP[i][j][0] = INT_MIN;
			DP[i][j][1] = INT_MIN;
			DP[i][j][2] = INT_MIN;
		}
	}
	bool check[1001][1001] = { false, };
	check[0][0] = true;
	cout << recursion(0, 0, graph[0][0], 2, check);

	//system("Pause");
}