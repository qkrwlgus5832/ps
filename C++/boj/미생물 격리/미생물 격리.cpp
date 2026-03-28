#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

class bug {
public:
	int x;
	int y;
	int count;
	int dir;
	int index;

	bug(int x, int y, int count, int dir, int index) {
		this->x = x;
		this->y = y;
		this->count = count;
		this->dir = dir;
		this->index = index;
	}
	bug() {
		this->x = 0;
		this->y = 0;
		this->count = 0;
		this -> dir = 0;
		this->index = 0;
	};
};

int dir[5][2] = { {0,0}, {-1,0},{1,0},{0,-1},{0,1} };


int curveddir(int x) {
	if (x == 1) {
		return 2;
	}
	if (x == 2) {
		return 1;
	}
	if (x == 3) {
		return 4;
	}
	if (x == 4) {
		return 3;
	}
}


int simulation(vector <bug> bugs) {


	for (int t = 1; t <= M; t++) {
		bug graph[121][121];
		int compare[121][121] = { 0, };

		for (int i = 0; i < bugs.size(); i++) {
			if (bugs[i].count > 0) {
				int ni = bugs[i].x + dir[bugs[i].dir][0];
				int nj = bugs[i].y + dir[bugs[i].dir][1];

				if (ni == 0 || nj == 0 || ni == N - 1 || nj == N - 1) {
					bugs[i].count /= 2;
					bugs[i].x = ni; bugs[i].y = nj;
					bugs[i].dir = curveddir(bugs[i].dir);
					graph[ni][nj] = bugs[i];
				}
				else if (graph[ni][nj].count > 0) {
					if (bugs[i].count > compare[ni][nj]) {
						compare[ni][nj] = bugs[i].count;

						bugs[i].count += graph[ni][nj].count;
						bugs[i].x = ni; bugs[i].y = nj;
						bugs[graph[ni][nj].index].count = 0;
						graph[ni][nj] = bugs[i];

					}
					else {
						bugs[graph[ni][nj].index].count += bugs[i].count;
						graph[ni][nj].count += bugs[i].count;
						bugs[i].count = 0;
					}

				}
				else {
					bugs[i].x = ni;
					bugs[i].y = nj;
					graph[ni][nj] = bugs[i];
					compare[ni][nj] = bugs[i].count;
				}
			}
		}
		if (t == M) {
			int result = 0;
			for (int i = 0; i <= N; i++) {
				for (int j = 0; j <= N; j++) {
					result += graph[i][j].count;
				}
			}
			return result;
		}
	}

}



int main() {
	int T;
	cin >> T;

	int x, y, count, dir;

	for (int t = 1; t <= T; t++) {
		vector <bug> bugs;
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &x, &y, &count, &dir);
			bugs.push_back(bug(x, y, count, dir, i));

		}
		printf("#%d %d\n", t, simulation(bugs));
	}
	return 0;
}