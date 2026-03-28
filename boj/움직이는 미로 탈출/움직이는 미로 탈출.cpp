#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;

char graph[9][9];
int dir[9][2] = { { 0,0 }, { 0,1 },{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1} };

int BFS(int i, int j, vector <pair <int, int>> v) {
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));

	while (q.size()) {
		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			q.pop();

			if (front.first == 0 && front.second == 7)
				return 1;
			
			if (graph[front.first][front.second] == '#')
				continue;

			for (int i1 = 0; i1 < 9; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= 8 || nj >= 8)
					continue;

				if (graph[ni][nj] == '.') {
					q.push(make_pair(ni, nj));
				}

			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].first < 8) {
				graph[v[i].first][v[i].second] = '.';
				v[i].first++;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first < 8) {
				graph[v[i].first][v[i].second] = '#';
			}
		}
	}
	return 0;
}


int main() {

	for (int i = 0; i < 8; i++) {
		scanf("%s", graph[i]);
	}
	vector <pair <int, int>> v;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (graph[i][j] == '#') {
				v.push_back(make_pair(i, j));
			}
		}
	}
	cout << BFS(7, 0, v);
	//system("Pause");
}