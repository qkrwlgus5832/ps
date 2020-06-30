#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

char graph[51][51];
int items[51][51];

int N, M;

class gyungjae {
public:
	int x;
	int y;
	int count;
	bool checkPoint[6] = { false, };

	gyungjae(int x, int y, int count) {
		this->x = x;
		this->y = y;
		this->count = count;
	}
};

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int BFS(int i, int j, int count) {
	queue <gyungjae> q;
	bool check[51][51][251] = { false, };
	check[i][j][0] = true;

	q.push(gyungjae(i, j, 0));

	int level = 0;
	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			gyungjae front = q.front();
			q.pop();

			if (graph[front.x][front.y] == 'E' && front.count == count) {
				return level;
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.x + dir[i1][0];
				int nj = front.y + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;

				int value = 0;
				int dd = 1;
				for (int j = 1; j <= 5; j++) {
					if (front.checkPoint[j] == true) {
						value += dd;
					}
					dd = dd << 1;
				}

				if (check[ni][nj][value] == true) {
					continue;
				}

		
				check[ni][nj][value] = true;

				gyungjae tmp = gyungjae(ni, nj, front.count);

				for (int j = 1; j<=5; j++) {
					tmp.checkPoint[j] = front.checkPoint[j];
				}
				
				if (graph[ni][nj] == 'X'){
					int index = items[ni][nj];
					if (front.checkPoint[index] == false) {
						tmp.checkPoint[index] = true;
						tmp.count++;
					}
					q.push(tmp);
					
				}
				else if (graph[ni][nj] != '#'){
					q.push(tmp);
				}
			}

		}
		level++;
	}


}


int main() {

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		scanf("%s", &graph[i]);
	}
	int count = 0;

	int starti, startj;
	int index = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 'S') {
				starti = i;
				startj = j;
			}
			if (graph[i][j] == 'X') {
				count++;
				items[i][j] = index++;
			}
			
		}
	}
	cout << BFS(starti, startj, count);
	//system("Pause");
}