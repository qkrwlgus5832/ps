#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

class node{
public:
	int x;
	int y;
	int count;
	char direction;

	node(int x, int y, int count, char direction) {
		this->x = x;
		this->y = y;
		this->count = count;
		this->direction = direction;
	}
};

string graph[101];
int check[101][101][4];

int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0},{1,0} };

int result = INT_MAX;

int H, W;

queue <node> q;

void queuePush(int dirIndex, int x, int y, int count) {
	int nx = x + dir[dirIndex][0];
	int ny = y + dir[dirIndex][1];

	if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
		return;
	}

	if (check[nx][ny][dirIndex] > count && graph[nx][ny] != '*') {
		check[nx][ny][dirIndex] = count;
		q.push(node(nx, ny, count, dirIndex));
	}
}
void BFS(pair <int,int> startLocation) {

	for (int i = 0; i <= 3; i++) {
		queuePush(i, startLocation.first, startLocation.second, 0);
		check[startLocation.first][startLocation.second][i] = 0;
	}

	while (q.size()) {
		node front = q.front();

		q.pop();

		if (graph[front.x][front.y] == 'C') {
			result = min(result, front.count);
			continue;
		}

		queuePush(front.direction, front.x, front.y, front.count);

		if (front.direction == 0 || front.direction == 1) {
			queuePush(2, front.x, front.y, front.count + 1);
			queuePush(3, front.x, front.y, front.count + 1);
		}
	
		else if (front.direction == 2 || front.direction == 3) {
			queuePush(0, front.x, front.y, front.count + 1);
			queuePush(1, front.x, front.y, front.count + 1);
		}
	
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> W >> H;

	pair <int, int> startLocation;

	memset(check, 1, sizeof(check));

	for (int i = 0; i < H; i++) {
		cin >> graph[i];
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (graph[i][j] == 'C') {
				startLocation = { i,j };
			}
		}
	}

	BFS(startLocation);

	cout << result;
	//system("Pause");
}
