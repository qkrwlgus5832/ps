#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int N, M;
int graph[9][9];
bool check[9][9];
int result = 0;

queue <pair <int, int>> virus;

void BFS(queue <pair <int, int>> q) {
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ni = front.first + dir[d][0];
			int nj = front.second + dir[d][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;

			if (graph[ni][nj] == 0 && check[ni][nj] == false) {
				check[ni][nj] = 1;
				graph[ni][nj] = 2;
				q.push(make_pair(ni, nj));
			}
		}
	}


}

void checkIfAnswer() {

	memset(check, false, sizeof(check));
	queue <pair <int, int>> q = virus;

	BFS(virus);
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				count++;
			}
		}
	}
	result = max(result, count);
}
void recursion(int index,  vector <pair <int,int>> v) {
	if (v.size() == 3) {
		int tmpgraph[9][9];
		memcpy(tmpgraph, graph, sizeof(graph));
		
		checkIfAnswer();

		memcpy(graph, tmpgraph, sizeof(graph));
		return;
	}

	for (int i2 = index; i2 < N*M; i2++) {
		int i1 = i2 / M;
		int j1 = i2 % M;

		if (graph[i1][j1] == 0) {
			v.push_back(make_pair(i1, j1));
			graph[i1][j1] = 1;
			if (j1 + 1 >= M) {
				recursion(i1 * M + j1 + 1, v);
			}
			else {
				recursion(i1 * M + j1 + 1, v);
			}

			v.pop_back();
			graph[i1][j1] = 0;
		}
	}
		
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 2) {
				virus.push(make_pair(i, j));
			}

		}
	
	}
	vector <pair <int,int>> v;
	recursion(0 , v);
	cout << result;
	//system("Pause");
}