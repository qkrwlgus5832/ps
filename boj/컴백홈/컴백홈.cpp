#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


char graph[6][6];
bool check[6][6];

int R, C, K;

int dir[4][2] = { { -1,0 },{1,0},{0,-1},{0,1} };

int result = 0;

void recursion(pair <int ,int> current, int depth) {
	if (current.first == 0 && current.second == C - 1) {
		if (depth == K)
			result++;
		return;
		
	}
	if (depth > K) {
		return;
	}
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = current.first + dir[i1][0];
		int nj = current.second + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= R || nj >= C)
			continue;

		if (graph[ni][nj] == '.' && check[ni][nj] == false) {
			check[ni][nj] = true;
			recursion({ ni,nj }, depth + 1);
			check[ni][nj] = false;
		}

	}
}

int main() {
	
	cin >> R >> C >> K;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
		}
	}

	check[R-1][0] = true;
	recursion({ R - 1, 0 }, 1);
	cout << result;
	//system("Pause");
}
