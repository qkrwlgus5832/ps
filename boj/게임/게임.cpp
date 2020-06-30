#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


char graph[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int result = 0;
int N, M;

int recursion(int i, int j, int dpcheck[51][51], bool check[51][51][4]) {
	int count = graph[i][j] -'0';

	int maxvalue = 0;

	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0] * count;
		int nj = j + dir[i1][1] * count;

		if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
			continue;
		}
		else if (dpcheck[ni][nj] > 0) {

			maxvalue = max(maxvalue, dpcheck[ni][nj]);
		}
		else if (graph[ni][nj] == 'H') {
			continue;
		}
		else if (check[ni][nj][i1] == true) {
			cout << -1;
			exit(0);
		}
		else {
			check[ni][nj][i1] = true;
			maxvalue = max(maxvalue,recursion(ni, nj,  dpcheck, check));
			check[ni][nj][i1] = false;
		}
		
	}
	dpcheck[i][j] = maxvalue + 1;
	return dpcheck[i][j];
}
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];

		}
	}
	int dpcheck[51][51] = { false, };
	bool check[51][51][4] = { false, };
	cout << recursion(0, 0, dpcheck, check);
	//system("Pause");
}