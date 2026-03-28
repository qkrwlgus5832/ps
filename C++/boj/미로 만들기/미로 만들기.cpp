#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits.h>

using namespace std;

int graph[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int check[51][51];
int n;

class node {
public:
	int x;
	int y;
	int count;

	node(int x, int y, int count) {
		this->x = x;
		this->y = y;
		this->count = count;
	}
};

int BFS(int i, int j) {
	int result = INT_MAX;

	queue <node> q;

	q.push(node(i, j, 0));
	check[i][j] = 0;


	while (q.size()) {
		node front = q.front();
		q.pop();
		if (front.x == n - 1 && front.y == n - 1) {
			result = min(result, front.count);
		}
		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.x + dir[i1][0];
			int nj = front.y + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
				continue;
			}

			if (graph[ni][nj] == 1 && (check[ni][nj] == -1 || check[ni][nj] > front.count)) {
				check[ni][nj] = front.count;
				q.push(node(ni, nj, front.count));
			}
			else if (graph[ni][nj] == 0 && (check[ni][nj] == -1 || check[ni][nj] > front.count + 1 )) {
				check[ni][nj] = front.count + 1;
				q.push(node(ni, nj, front.count + 1));
			}
		}
	}
	return result;

}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	memset(check, -1, sizeof(check));
	cout << BFS(0 , 0);

	//system("Pause");
}
