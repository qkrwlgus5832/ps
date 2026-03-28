#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, M, k;

vector <int> direction[401][4];

pair <int, int> shark[21][21];
pair <int, int> smell[21][21];

int dir[5][2] = { {0,0}, {-1,0},{1,0},{0,-1},{0,1} };



bool checkIfAnswer() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (shark[i][j].first > 1) {
				count++;
			}
		}
	}
	if (count > 0)
		return false;
	return true;
}


void moveShark(int i, int j, pair <int, int> tmpshark[21][21], int time, pair <int, int> tmpsmell[21][21]) {
	vector <int> dir_ = direction[shark[i][j].first - 1][shark[i][j].second - 1];

	int firstDirection = -1;
	int secondDirection = -1;

	for (int dirIndex = dir_.size() - 1; dirIndex >= 0; dirIndex--) {
		int ni = i + dir[dir_[dirIndex]][0];
		int nj = j + dir[dir_[dirIndex]][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;

		if (smell[ni][nj].first == 0) {
			firstDirection = dir_[dirIndex];

		}
		if (smell[ni][nj].first == shark[i][j].first) {
			secondDirection = dir_[dirIndex];

		}
	}
	int ni = 0;
	int nj = 0;

	if (firstDirection == -1) {
		ni = i + dir[secondDirection][0];
		nj = j + dir[secondDirection][1];
		shark[i][j].second = secondDirection;
	}
	else {
		ni = i + dir[firstDirection][0];
		nj = j + dir[firstDirection][1];
		shark[i][j].second = firstDirection;
	}
	if (tmpshark[ni][nj].first == 0 || tmpshark[ni][nj].first > shark[i][j].first) {
		tmpsmell[ni][nj].first = shark[i][j].first;
		tmpsmell[ni][nj].second = time;

		tmpshark[ni][nj] = shark[i][j];
	}
}

void removeSmell(int time) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (time - smell[i][j].second >= k) {
				smell[i][j] = { 0,0 };
			}
		}
	}
}
int simulation() {

	for (int time = 1; time <= 1000; time++) {

		pair <int, int> tmpshark[21][21];
		memset(tmpshark, 0, sizeof(tmpshark));
		pair <int, int> tmpsmell[21][21];
		memcpy(tmpsmell, smell, sizeof(tmpsmell));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (shark[i][j].first > 0) {
					moveShark(i, j, tmpshark, time, tmpsmell);
				}
			}
		}

		memcpy(smell, tmpsmell, sizeof(smell));
		memcpy(shark, tmpshark, sizeof(shark));

		removeSmell(time);

		if (checkIfAnswer())
			return time;
	}
	return -1;
}


int main() {
	cin >> N >> M >> k;


	int tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (tmp > 0) {
				shark[i][j].first = tmp;
			}
			smell[i][j] = { tmp, 0 };
		}
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d", &tmp);
		for (int i1 = 0; i1 < N; i1++) {
			for (int j1 = 0; j1 < N; j1++) {
				if (shark[i1][j1].first == i) {
					shark[i1][j1].second = tmp;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int j1 = 0; j1 < 4; j1++) {
				scanf("%d", &tmp);
				direction[i][j].push_back(tmp);
			}
		}
	}


	cout << simulation();
	//system("Pause");
}