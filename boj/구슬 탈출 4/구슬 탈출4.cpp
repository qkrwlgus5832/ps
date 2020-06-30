#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;

char graph[11][11];

int dir[4][2] = { {-1, 0}, {1, 0} , {0, -1}, {0, 1} };

bool visit[11][11][11][11];

bool resultflag = false;
enum color {
	red,
	blue
};

class bead {
public:
	int x;
	int y;
	int color;
};

bead bluebead;
bead redbead;

class beads {
public:
	bead bluebead;
	bead redbead;
	beads(bead bluebead, bead redbead) {
		this->bluebead = bluebead;
		this->redbead = redbead;
	}
};

bool beadBFS(int dirindex, bead& bead_, bead& otherbead_) {
	queue <bead> q;
	q.push(bead_);
	while (!q.empty()) {
		int frontx = q.front().x;
		int fronty = q.front().y;
		bead& tmp = q.front();

		q.pop();

		int nx = frontx + dir[dirindex][0];
		int ny = fronty + dir[dirindex][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			return false;
		else if (graph[nx][ny] == 'O') {
			tmp.x = nx; tmp.y = ny;
			q.push(tmp);
			bead_ = tmp;
			return true;
		}
		else if (nx == otherbead_.x && ny == otherbead_.y)
			continue;

		else if (graph[nx][ny] != '#') {
			tmp.x = nx; tmp.y = ny;
			q.push(tmp);
			bead_ = tmp;
		}

	}
	return false;
}

int bfsbluefirst(int front, bead& tmpbluebead, bead& tmpredbead) {
	if (beadBFS(front, tmpbluebead, tmpredbead) == true)
		return -1;

	if (beadBFS(front, tmpredbead, tmpbluebead))
		return 1;

	return 0;
}

int bfsredfirst(int front, bead& tmpbluebead, bead& tmpredbead) {
	if (beadBFS(front, tmpredbead, tmpbluebead) == true) {
		if (beadBFS(front, tmpbluebead, tmpredbead) == true) {
			return -1;
		}
		else
			return 1;
	}
	if (beadBFS(front, tmpbluebead, tmpredbead))
		return -1;

	return 0;
}
int BFS() {
	queue <pair <int, beads>> q;
	int time = 0;
	q.push(make_pair(0, beads(bluebead, redbead)));
	q.push(make_pair(1, beads(bluebead, redbead)));
	q.push(make_pair(2, beads(bluebead, redbead)));
	q.push(make_pair(3, beads(bluebead, redbead)));

	visit[bluebead.x][bluebead.y][redbead.x][redbead.y] = true;

	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			bead tmpbluebead = q.front().second.bluebead;
			bead tmpredbead = q.front().second.redbead;
			int front = q.front().first;
			q.pop();

			int resultingflag = 0;

			if (front == 0) {
				if (tmpbluebead.x > tmpredbead.x) {
					resultingflag = bfsredfirst(front, tmpbluebead, tmpredbead);
				}
				else {
					resultingflag = bfsbluefirst(front, tmpbluebead, tmpredbead);
				}
			}
			else if (front == 1) {
				if (tmpredbead.x > tmpbluebead.x) {
					resultingflag = bfsredfirst(front, tmpbluebead, tmpredbead);
				}
				else {
					resultingflag = bfsbluefirst(front, tmpbluebead, tmpredbead);
				}
			}

			else if (front == 2) {
				if (tmpredbead.y < tmpbluebead.y) {
					resultingflag = bfsredfirst(front, tmpbluebead, tmpredbead);
				}
				else {
					resultingflag = bfsbluefirst(front, tmpbluebead, tmpredbead);

				}
			}
			else if (front == 3) {
				if (tmpbluebead.y < tmpredbead.y) {
					resultingflag = bfsredfirst(front, tmpbluebead, tmpredbead);

				}
				else {
					resultingflag = bfsbluefirst(front, tmpbluebead, tmpredbead);
				}
			}

			if (resultingflag == 1) {
				return time + 1;
			}
			else if (resultingflag == -1)
				continue;

			if (visit[tmpbluebead.x][tmpbluebead.y][tmpredbead.x][tmpredbead.y] == true)
				continue;

			visit[tmpbluebead.x][tmpbluebead.y][tmpredbead.x][tmpredbead.y] = true;

			for (int i = 0; i < 4; i++) {
				q.push(make_pair(i, beads(tmpbluebead, tmpredbead)));

			}

		}
		time++;
	}
	return -1;
}
int main() {
	cin >> N >> M;
	cin.tie(NULL);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'B') {
				bluebead.x = i;
				bluebead.y = j;
				bluebead.color = color::red;
			}
			else if (graph[i][j] == 'R') {
				redbead.x = i;
				redbead.y = j;
				redbead.color = color::blue;
			}
		}
	}
	int d = BFS();
	if (d == -1) {
		cout << -1;
	}
	else {
		cout << d;
	}
	//("Pause");
}