#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <memory.h>

using namespace std;

char graph[51][51];
char tmpgraph[51][51];

vector <pair <int,int>> mirror;
int result = INT_MAX;

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
vector <pair <int, int>> doors;
int bfscheck[51][51][2];

int N;

class node {
public:
	int x;
	int y;
	int direction;
	int count = 0;

	node(int x, int y, int direction, int count) {
		this->x = x;
		this->y = y;
		this->direction = direction;
		this->count = count;
	}
};

pair <int, int> changeDirection(int dir) {
	if (dir == 0)
		return { 2,3 };
	else if (dir == 1)
		return { 2,3 };
	else if (dir == 2)
		return { 0,1 };

	return { 0,1 };
}

void bfs(pair <int ,int> door) {
	queue <node> q;


	q.push(node(door.first, door.second, 0, 1));
	q.push(node(door.first, door.second, 1, 1));
	q.push(node(door.first, door.second, 2, 1));
	q.push(node(door.first, door.second, 3, 1));

	bfscheck[doors[0].first][doors[0].second][0] = 1;
	bfscheck[doors[0].first][doors[0].second][1] = 1;


	while (q.size()) {
		node front = q.front();
		q.pop();

		if (front.x == doors[1].first && front.y == doors[1].second) {
			result = min(result, front.count - 1);
			continue;
		}

		int ni = front.x + dir[front.direction][0];
		int nj = front.y + dir[front.direction][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= N || graph[ni][nj] == '*')
			continue;

		if (graph[ni][nj] == '!') {
		
			pair <int, int> tmp = changeDirection(front.direction);

			if (bfscheck[ni][nj][tmp.first /2] ==0 || bfscheck[ni][nj][tmp.first / 2] > front.count + 1) {
				q.push(node(ni, nj, tmp.first, front.count + 1));
				q.push(node(ni, nj, tmp.second, front.count + 1));
				bfscheck[ni][nj][tmp.first / 2] = front.count + 1;
				bfscheck[ni][nj][tmp.second / 2] = front.count + 1;
			}
		
		}
		if (bfscheck[ni][nj][front.direction/2] == 0 || bfscheck[ni][nj][front.direction/2 ] > front.count) {
			q.push(node(ni, nj, front.direction, front.count));
			bfscheck[ni][nj][front.direction / 2] = front.count;
		}
		
	}
}


int main() {
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '!') {
				mirror.push_back({ i,j });
			}
			else if (graph[i][j] == '#') {
				doors.push_back({ i,j });
			}
		}
	}
	bfs(doors[0]);

	cout << result;
	//system("Pause");
}