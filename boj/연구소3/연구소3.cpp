#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int graph[51][51];

vector <pair <int, int>> virus;

int result = -1;

int dir[4][2] = { {-1,0}, {1,0},{0, -1},{0,1} };

int zerocount = 0;
int BFS(vector <int> v) {
	queue <pair <int, int>> q;

	bool check[51][51] = { false, };
	for (int i = 0; i < v.size(); i++) {
		check[virus[v[i]].first][virus[v[i]].second] = true;
		q.push(make_pair(virus[v[i]].first, virus[v[i]].second));
	}
	int level = 0;
	int count = 0;

	if (zerocount == count) {
		return 0;
	}
	while (q.size()) {
		int s = q.size();
		for (int ts = 0; ts < s; ts++) {
			pair <int, int> front = q.front();
			q.pop();


			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= N || graph[ni][nj] == 1)
					continue;

				if (check[ni][nj] == false) {
					if (graph[ni][nj] == 0) {
						count++;
					}
					if (count == zerocount) {
						return level + 1;
					}
					check[ni][nj] = true;

					q.push(make_pair(ni, nj));

				}
			}
		}
		level++;
	}
	return -1;
}


void recursion(int i1, vector <int> v) {
	if (v.size() == M) {
		int tmp = BFS(v);
		if (tmp != -1) {
			if (result == -1) {
				result = tmp;
			}
			else {
				result = min(result, tmp);
			}
		}
	}
	for (int i = i1; i < virus.size();  i++) {
		v.push_back(i);
		recursion(i + 1, v);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			else if (graph[i][j] == 0) {
				zerocount++;
			}
		}
	}
	vector <int> v;
	recursion(0, v);
	cout << result;
	//system("Pause");
}