#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int N, M, K;

int graph[11][11];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int result = INT_MIN;

void recursion(int index, bool check[11][11], int value, int count) {
	if (count == K) {
		result = max(result, value);
		return;
	}
	for (int i = index; i < N * M; i++) {
		int i1 = i / M;
		int j1 = i % M;

		bool flag = false;
		for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
			int ni = i1 + dir[dirIndex][0];
			int nj = j1 + dir[dirIndex][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;
			if (check[ni][nj] == true) {
				flag = true;
			}
		}
		if (flag)
			continue;

		if (check[i1][j1] == false) {
			check[i1][j1] = true;

			recursion(index + 1, check, value + graph[i1][j1], count+1);
			check[i1][j1] = false;

		}
	}
}
int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	bool check[11][11] = { false, };

	recursion(0, check, 0, 0);
	cout << result;
	//system("Pause");
}
