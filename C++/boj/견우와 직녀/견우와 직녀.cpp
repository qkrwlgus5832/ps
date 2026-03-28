#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int graph[11][11];
int N, M;

class node {
public:
	int x;
	int y;
	bool flag = false;
	int time = 0;

	node(int x, int y, bool flag, int time) {
		this->x = x;
		this->y = y;
		this->flag = flag;
		this->time = time;
	}
};

int getTime(int M, int time) {
	for (int i = 0; i < 21; i++) {
		if (time % M == 0)
			return time;
		time++;
	}
}
int dir[4][2] = {{ -1,0 }, { 1,0 },{0,-1},{0,1} };

int BFS(int i, int j) {
	queue <node> q;

	q.push(node(i, j, false , 0));

	int time = 0;

	bool check[11][11] = { false, };
	
	check[i][j] = true;

	while (q.size()) {

		node front = q.front();
		q.pop();
		if (front.x == N - 1 && front.y == N - 1)
			return front.time;
		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.x + dir[i1][0];
			int nj = front.y + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				continue;
			if (graph[ni][nj] == 0)
				continue;
			if (graph[ni][nj] >= 2 && front.flag) {
				continue;
			}
			if (check[ni][nj] == true)
				continue;

			check[ni][nj] = true;
			if (graph[ni][nj] >= 2) {
				q.push(node(ni, nj, true, getTime(graph[ni][nj], front.time) + 1));
			}
			else {
				q.push(node(ni, nj, false, front.time + 1));
			}
		}
	}
	return INT_MAX;
}


bool checkIfCan(int i, int j) {

	if ((j + 1 < N && graph[i][j + 1] == 0) || (j - 1 >= 0 && graph[i][j - 1] == 0)) {
		if (i + 1 < N && graph[i + 1][j] == 0)
			return false;
	}
	return true;
}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	int result = BFS(0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 0) {
				if (checkIfCan(i, j) == false)
					continue;
				graph[i][j] = M;
				result = min(result,BFS(0, 0));
				graph[i][j] = 0;
			}
		}
	}
	cout << result;
	system("Pause");
}