#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int graph[51][51];

vector<pair <int, int>> airConditional;

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C, T;

int clockwise[2][4] = {
	{ 3, 0, 2, 1 },
	{ 3, 1, 2, 0 }
};
void spread() {
	int tmpgraph[51][51] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int count = 0;
			if (graph[i][j] == -1) {
				continue;
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = i + dir[i1][0];
				int nj = j + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= R || nj >= C)
					continue;
				if (graph[ni][nj] == -1)
					continue;
				count++;
				tmpgraph[ni][nj] += (graph[i][j] / 5);
				tmpgraph[i][j] -= (graph[i][j] / 5);
			}
			
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			graph[i][j] += tmpgraph[i][j];
		}
	}
}

void recursion(pair <int, int> location, int isClockwise, int index, int value) {
	int ni = location.first + dir[clockwise[isClockwise][index]][0];
	int nj = location.second + dir[clockwise[isClockwise][index]][1];
	int tmp = graph[location.first][location.second];

	graph[location.first][location.second] = value;

	if (graph[ni][nj] == -1) {
		return;
	}
	if (ni < 0 || nj < 0 || ni >= R || nj >= C) {
		int ni = location.first + dir[clockwise[isClockwise][index + 1]][0];
		int nj = location.second + dir[clockwise[isClockwise][index + 1]][1];
		recursion(make_pair(ni,nj), isClockwise, index + 1, tmp);
		return;
	}
	recursion(make_pair(ni, nj), isClockwise, index, tmp);


}

void cleaning() {
	recursion(airConditional[0], 0, 0, 0);
	recursion(airConditional[1], 1, 0, 0);
}
int main() {

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == -1) {
				airConditional.push_back(make_pair(i, j));
			}
		}
	}
	airConditional[0].second++;
	airConditional[1].second++;
	for (int i = 0; i < T; i++) {
		spread();
		cleaning();
	}
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] != -1) {
				result += graph[i][j];
			}
		}
	}
	cout << result;
	system("Pause");
}