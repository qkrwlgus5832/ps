#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

char graph[201][201];
int bomb[201][201];

int R, C, N;

void setBomb(int time) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == '.') {
				bomb[i][j] = time;
				graph[i][j] = 'O';
			}
		}
	}
}

int dir[5][2] = { {0,0}, {-1,0}, {1,0}, {0,-1}, {0,1} };

void Pop(int time) {
	char tmpgraph[201][201];
	int tmpbomb[201][201];

	memcpy(tmpgraph, graph, sizeof(tmpgraph));

	memcpy(tmpbomb, bomb, sizeof(tmpbomb));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (tmpgraph[i][j] == 'O' && time - tmpbomb[i][j] == 3) {

				for (int i1 = 0; i1 < 5; i1++) {
					int ni = i + dir[i1][0];
					int nj = j + dir[i1][1];
					if (ni < 0 || nj < 0 || ni >= R || nj >= C)
						continue;
					
					graph[ni][nj] = '.';
					bomb[ni][nj] = -1;
				}
			}
			
		}
	}
}
int main() {

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		scanf("%s", graph[i]);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 'O')
				bomb[i][j] = 0;
		}
	}

	for (int t = 1; t <= N; t++) {
		if (t == 1) {
			continue;
		}
		if (t % 2 == 0) {
			setBomb(t);
		}
		else {
			Pop(t);
		}

	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", graph[i][j]);
		}
		printf("\n");
	}
	//system("Pause");
}