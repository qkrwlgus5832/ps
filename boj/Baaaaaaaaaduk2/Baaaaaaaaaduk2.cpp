#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int graph[21][21];


int result = 0;

int N, M;

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int BFS(int i, int j, bool check[21][21]) {
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;

	int count = 1;
	bool flag = false;

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;
			if (check[ni][nj] == false) {

				if (graph[ni][nj] == 2) {
					check[ni][nj] = true;
					q.push(make_pair(ni, nj));
					count++;
				}
				else if (graph[ni][nj] == 0) {
					flag = true;
				}
			}
		}
	}
	if (flag)
		return 0;
	return count;
}

void recursion(int i, vector<pair <int,int>> v, int count) {
	if (count == 2) {
		int count_ = 0;
		bool check[21][21] = { false, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == false && graph[i][j] == 2) {
					count_ += BFS(i, j, check);
				}
			}
		}
		result = max(result, count_);
		return;
	}

	for (int index = i; index < v.size(); index++) {
		graph[v[index].first][v[index].second] = 1;
		recursion(index + 1, v, count + 1);
		graph[v[index].first][v[index].second] = 0;
	}
}
int main() {


	vector <pair <int, int>> v;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	recursion(0, v, 0);
	cout << result;
	//system("Pause");

}