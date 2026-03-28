#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int graph[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool check[101][101][2];
int N, M, T;

class node {
public:
	int x;
	int y;
	bool flag;

	node(int x, int y, bool flag) {
		this->x = x;
		this->y = y;
		this->flag = flag;
	}
};
int BFS(int i, int j) {
	queue <node> q;
	q.push(node(i, j, false));

	int level = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			node front = q.front();
			q.pop();

			if (front.x == N - 1 && front.y == M - 1) {
				return level;
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.x + dir[i1][0];
				int nj = front.y + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;

				if (check[ni][nj][front.flag] == true)
					continue;

				check[ni][nj][front.flag] = true;

				if (graph[ni][nj] == 0) {
					q.push(node(ni, nj, front.flag));
				}
				else if (graph[ni][nj] == 1 && front.flag == true) {
					q.push(node(ni, nj, true));
				}
				else if (graph[ni][nj] == 2) {
					q.push(node(ni, nj, true));
				}
			}
		}
		level++;
		if (level == T + 1)
			return -1;
	}
	return -1;
}
int main() {

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	int result = BFS(0, 0);
	if (result == -1) {
		cout << "Fail";
	}
	else {
		cout << result;
	}
	
	//system("Pause");
}