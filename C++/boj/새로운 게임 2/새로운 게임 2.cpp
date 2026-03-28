#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[13][13];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int N, K;

vector <int> A[13][13];

class horse {
public:
	int x;
	int y;
	int dir;

	horse(int x, int y, int dir) {
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};
vector <horse> horses;


int curveDir(int dir) {
	if (dir == 0)
		return 1;
	if (dir == 1)
		return 0;
	if (dir == 2)
		return 3;
	if (dir == 3)
		return 2;
}


bool checkIfAnswer() {
	for (int i1 = 0; i1 < 12; i1++) {
		for (int j1 = 0; j1 < 12; j1++) {
			if (A[i1][j1].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}


bool move() {
	for (int i = 0; i < horses.size(); i++) {
		int ni = horses[i].x + dir[horses[i].dir][0];
		int nj = horses[i].y + dir[horses[i].dir][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= N || graph[ni][nj] == 2) {
			horses[i].dir = curveDir(horses[i].dir);
			ni = horses[i].x + dir[horses[i].dir][0];
			nj = horses[i].y + dir[horses[i].dir][1];
		}
		if (ni < 0 || nj < 0 || ni >= N || nj >= N || graph[ni][nj] == 2) {
			continue;
		}
		deque <int> tmp;
		int count = 0;

		if (graph[ni][nj] == 0) {

			for (int i1 = 0; i1 < A[horses[i].x][horses[i].y].size(); i1++) {
				if (A[horses[i].x][horses[i].y][i1] == i) {
					tmp.push_back(A[horses[i].x][horses[i].y][i1]);
					count = 1;
				}
				else if (count> 0) {
					count++;
					tmp.push_back(A[horses[i].x][horses[i].y][i1]);
				}
			}

		}
		else if (graph[ni][nj] == 1) {
			for (int i1 = 0; i1 < A[horses[i].x][horses[i].y].size(); i1++) {
				if (A[horses[i].x][horses[i].y][i1] == i) {
					tmp.push_front(A[horses[i].x][horses[i].y][i1]);
					count = 1;
				}
				else if (count > 0) {
					count++;
					tmp.push_front(A[horses[i].x][horses[i].y][i1]);
				}
			}
		}
		for (int j = 0; j < count; j++) {
			A[horses[i].x][horses[i].y].pop_back();
		}
		for (int j = 0; j < tmp.size(); j++) {
			A[ni][nj].push_back(tmp[j]);
			horses[tmp[j]].x = ni;
			horses[tmp[j]].y = nj;

		}
		if (checkIfAnswer())
			return true;
	}
	return false;
}


int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	int x, y, dir;

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &x, &y, &dir);
		horses.push_back(horse(--x, --y, --dir));
		A[x][y].push_back(i);

	}

	for (int i = 1; i <= 1000; i++) {
		if (move()) {
			cout << i;
			return 0;
		}
		
	}
	cout << -1;
	//system("Pause");
}