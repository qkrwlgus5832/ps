#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N, M;

int graph[51][51];

int dir[4][2] = { { -1,0 }, {0, 1},{1,0} ,{0,-1} };
int backdir[4][2] = { {1,0}, {0, -1}, {-1,0}, {0,1} };

int rotateddir[4] = { 3, 0, 1, 2 };

class robot {
public:
	int x;
	int y;
	int direction;
	robot(int x, int y, int direction) {
		this->x = x;
		this->y = y;
		this->direction = direction;
	}
	robot() {};
};

robot currentRobot;

void cleaning(int i, int j, int count, int direction) {
	if (count == 4) {
		int ni = i + backdir[direction][0];
		int nj = j + backdir[direction][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			return;
		if (graph[ni][nj] == 1)
			return;
		cleaning(ni, nj, 0, direction);
		return;
	}
	
	int ni = i + dir[rotateddir[direction]][0];
	int nj = j + dir[rotateddir[direction]][1];


	if ( ni >=0 && nj >=0 && ni <N && nj <M && graph[ni][nj] == 0) {
		graph[ni][nj] = 2;
		cleaning(ni, nj, 0, rotateddir[direction]);
	}
	else {
		
		cleaning(i, j, count + 1, rotateddir[direction]);
	}


}

int main() {
	cin >> N >> M;
	
	int r, c, d;
	cin >> r >> c >> d;
	currentRobot = robot(r, c, d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	graph[currentRobot.x][currentRobot.y] = 2;
	cleaning(currentRobot.x, currentRobot.y, 0, currentRobot.direction);

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 2) {
				result++;
			}
		}
	}
	cout << result;
	//system("Pause");
}