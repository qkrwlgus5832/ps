#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;


int R, C;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void BFS(int r, int c, char graph[101][101], bool bfscheck[101][101]) {
	vector <pair <int, int>> check;

	bfscheck[r][c] = true;
	bool currentcheck[101][101] = { false, };
	currentcheck[r][c] = true;
	check.push_back(make_pair(r, c));
	queue <pair <int, int>> q;
	q.push(make_pair(r, c));

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		if (front.first == 1)
			return;

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 1 || nj < 1 || nj > C || ni >R) {
				continue;
			}
			if (bfscheck[ni][nj] == false && graph[ni][nj] == 'x') {
				bfscheck[ni][nj] = true;
				currentcheck[ni][nj] = true;
				q.push(make_pair(ni, nj));
				check.push_back(make_pair(ni, nj));
			}
		}
	}
	int count = -1;
	for (int j = 1; j <= C; j++) {
		for (int i = 1; i <= R; i++) {
			if (graph[i][j] == 'x' && currentcheck[i][j]) {
				int tmpcount = 0;
				for (int i1 = i- 1; i1 >= 1; i1--) {
					if (graph[i1][j] == '.') {
						tmpcount++;
					}
					else
						break;
				}
				if (count == -1) {
					count = tmpcount;
				}
				else {
					count = min(count, tmpcount);
				}
				break;
			}
		}
	}
	if (count != -1) {
		for (int i = 0; i < check.size(); i++) {
			graph[check[i].first][check[i].second] = '.';
			check[i].first -= count;
		}
		for (int i = 0; i < check.size(); i++) {
			graph[check[i].first][check[i].second] = 'x';
		}
	}
}

void simulation(char graph[101][101]) {

	bool bfscheck[101][101] = { false, };
	char tmpgraph[101][101];

	memcpy(tmpgraph, graph, sizeof(tmpgraph));

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (bfscheck[i][j] == false && tmpgraph[i][j] == 'x') {
				BFS(i, j, graph, bfscheck);
			}
		}
	}
}
void mineral(int index, char graph[101][101], int order) {
	order = order % 2;

	if (order == 0) {
		for (int i = 1; i <= C; i++) {
			if (graph[index][i] == 'x') {
				graph[index][i] = '.';
				simulation(graph);
				break;
			}
		}
	}
	else {
		for (int i = C; i >= 1; i--) {
			if (graph[index][i] == 'x') {
				graph[index][i] = '.';
				simulation(graph);
				break;
			}
		}
	}
}
int main() {

	cin >> R >> C;

	char graph[101][101];
	
	char dd;
	for (int i = R; i >=1; i--) {
		scanf("%s", &graph[i]);

	}
	int N;
	cin >> N;
	
	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		mineral(tmp, graph, i);

	}

	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			printf("%c", graph[i][j]);
		}
		printf("\n");
	}
	system("Pause");
}