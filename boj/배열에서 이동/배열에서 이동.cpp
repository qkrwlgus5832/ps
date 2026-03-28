#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <limits.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;
int graph[101][101];
int dir[4][2] = { {-1, 0 }, {1,0}, {0, -1} ,{0,1} };


class node {
public:
	int x; 
	int y;
	int minValue;
	int maxValue;
	char direction;

	node(int x, int y, int minValue, int maxValue, char direction) {
		this->x = x;
		this->y = y;
		this->minValue = minValue;
		this->maxValue = maxValue;
		this->direction = direction;
	}

};

int getReverseDirection(int i) {
	if (i == 0)
		return 1;
	if (i == 1)
		return 2;
	if (i == 2)
		return 3;
	if (i == 3)
		return 2;
	return 4;

}
int BFS(int x, int y) {
	queue <node> q;

	bool check[101][101] = { false, };
	int result = INT_MAX;

	q.push(node(x, y, graph[x][y], graph[x][y], -1));
	check[x][y] = true;

	while (q.size()) {
		node front = q.front();
		q.pop();

		if (front.x == n - 1 && front.y == n - 1) {
			result = min(result, front.maxValue - front.minValue);
			continue;
		}
		for (int i1 = 0; i1 < 4; i1++) {
			if (getReverseDirection(i1) == front.direction)
				continue;

			int ni = front.x + dir[i1][0];
			int nj = front.y + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= n || nj >= n)
				continue;

			if (check[ni][nj] == false) {
			int minValue = min(front.minValue, graph[ni][nj]);
			int maxValue = max(front.maxValue, graph[ni][nj]);

			check[ni][nj] = true;
			q.push(node(ni, nj, minValue, maxValue, i1));

		}
	}

	return result;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	cout << BFS(0, 0);

	system("Pause");
}
