#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N;

int dir[4][2] = { {0,1}, {-1,0},{0,-1}, {1,0} };

bool check[101][101];

int curveDirection(int direction) {
	if (direction == 0) {
		return 1;
	}
	else if (direction == 1) {
		return 2;
	}
	else if (direction == 2) {
		return 3;
	}
	else if (direction == 3) {
		return 0;
	}
}

void recursion(deque <int> q, pair <int, int> endpoint, int g) {
	if (g == 0) {
		return;
	}
	int s = q.size();

	for (int i = s - 1; i >= 0; i--) {
		int curvedDir = curveDirection(q[i]);
		q.push_back(curvedDir);
		endpoint.first += dir[curvedDir][0];
		endpoint.second += dir[curvedDir][1];
		check[endpoint.first][endpoint.second] = true;
	}
	recursion(q, endpoint, g-1);
	
}

void makeDragonCurve(int x, int y, int d, int g) {
	check[x][y] = true;
	pair <int, int> endpoint;
	int ni = x + dir[d][0];
	int nj = y + dir[d][1];

	check[ni][nj] = true;

	endpoint.first = ni;
	endpoint.second = nj;

	deque <int> q;
	q.push_back(d);
	
	recursion(q, endpoint, g);
}

int main() {
	cin >> N;
	int x, y, d, g;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &y, &x, &d, &g);
		makeDragonCurve(x, y, d, g);
	}

	int result = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <=100; j++) {
			bool flag = true;
			for (int i1 = 0; i1 < 2; i1++) {
				for (int j1 = 0; j1 < 2; j1++) {
					if (i + i1 > 100 || j + j1 > 100)
						flag = false;
					if (check[i + i1][j + j1] == false)
						flag = false;
				}
			}
			if (flag == true) {
				result++;
			}
		}

	}
	cout << result;
	//system("Pause");
}