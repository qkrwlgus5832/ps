#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int graph[21][21];

pair <int, int> start;
int N, M;
long long oil;

struct customer {
	int x;
	int y;
	int index;
};
customer customers[][21];

int dir[][2] = { { -1,0 },{1,0},{0,-1},{0,1} };

int BFS(pair <int ,int> car, pair <int, int> person) {
	bool bfscheck[21][21] = { false, };
	queue <pair <int, int>> q;
	q.push(car);
	bfscheck[car.first][car.second] = true;

	int length = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			q.pop();

			if (front == person)
				return length;

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;

				if (bfscheck[ni][nj] == false && graph[ni][nj] == 0) {
					bfscheck[ni][nj] = true;
					q.push({ ni,nj });
				}
			}
		}
		length++;
	}

	return -1;
}

int search() {
	int length = INT_MAX;
	pair <int, int> location = { -1,-1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (customers[i][j].index > 0) {
				int tmp = BFS(start, {i ,j});
				if (tmp != -1 && length > tmp) {
					length = tmp;
					location = { i,j };
				}
			}
		}
	}
	
	if (location.first == -1 && location.second == -1) {
		return -1;
	}

	oil -= length;

	if (oil < 0)
		return -1;

	int length2 = BFS(location, { customers[location.first][location.second].x, customers[location.first][location.second].y });
	
	if (length2 == -1)
		return -1;

	oil -= length2;

	if (oil < 0) {
		return -1;
	}

	customers[location.first][location.second].index = -1;

	oil += length2 * 2;
	start = { customers[location.first][location.second].x, customers[location.first][location.second].y };
	return 0;
}
int main() {

	cin >> N >> M >> oil;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	cin >> start.first >> start.second;
	start.first--;
	start.second--;

	int x, y, x1, y1;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x, &y, &x1, &y1);
		customers[x - 1][y- 1] = { x1 - 1, y1- 1, i +1 };
	}

	int count = 0;

	while (1) {
		if (search() == -1) {
			cout << -1;
			break;
		}
		count++;

		if (count == M) {
			cout << oil;
			break;
		}
	}

	//system("Pause");
}
