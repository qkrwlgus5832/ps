#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, G, R;

int result = 0;
int dir[4][2] = { { -1,0 }, {1,0},{0,-1},{0,1} };
int garden[51][51];

int BFS(queue <pair <int, int>> r, queue <pair <int, int>> g, int redcheck[51][51], int greencheck[51][51]) {
	int level = 2;
	int count = 0;


	while (r.size() || g.size()) {
		int rs = r.size();
		int gs = g.size();

		for (int qs = 0; qs < rs; qs++) {
			pair <int, int> front = r.front();
			r.pop();
			if (redcheck[front.first][front.second] == -1 && greencheck[front.first][front.second] == -1)
				continue;

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M || garden[ni][nj] == 0 || redcheck[ni][nj] >0 || greencheck[ni][nj] > 0)
					continue;
				if (redcheck[ni][nj] == -1 && greencheck[ni][nj] == -1)
					continue;
				redcheck[ni][nj] = level;
				r.push(make_pair(ni, nj));
			}
		}
		for (int qs = 0; qs < gs; qs++) {
			pair <int, int> front = g.front();
			g.pop();

			if (redcheck[front.first][front.second] == -1 && greencheck[front.first][front.second] == -1)
				continue;

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M || garden[ni][nj] == 0 ||  greencheck[ni][nj] > 0)
					continue;
				if (redcheck[ni][nj] == -1 && greencheck[ni][nj] == -1)
					continue;
				if (redcheck[ni][nj] > 0) {
					if (redcheck[ni][nj] == level) {
						redcheck[ni][nj] = -1;
						greencheck[ni][nj] = -1;
						count++;

					}
					continue;
				}
				greencheck[ni][nj] = level;
				g.push(make_pair(ni, nj));
			}
		}
		
		level++;
	}
	return count;

}


int initBFS(vector <pair <int, int>> red, vector <pair <int, int>> green) {
	queue <pair <int, int>> r;
	queue <pair <int, int>> g;

	int redcheck[51][51] = { 0, };
	int greencheck[51][51] = { 0, };

	for (int i = 0; i < red.size(); i++) {
		r.push(red[i]);
		redcheck[red[i].first][red[i].second] = 1;
	}
	for (int i = 0; i < green.size(); i++) {
		g.push(green[i]);
		greencheck[green[i].first][green[i].second] = 1;
	}

	return BFS(r, g, redcheck, greencheck);
}
bool flag = false;

void recursion(vector <pair <int, int>> red, vector <pair <int, int>> green, bool check[51][51], int G, int R, int index, vector <pair <int ,int>> v) {
	if (G == 0 && R == 0) {
		result = max(result, initBFS(red, green));
		if (result == 12) {
			initBFS(red, green);
		}
		return;
	}

	for (int i1 = index; i1 < v.size(); i1++) {
		int i = v[i1].first;
		int j = v[i1].second;

		if (R > 0) {
			red.push_back(make_pair(i, j));
			check[i][j] = true;
			recursion(red, green, check, G, R - 1, i1 + 1, v);
			check[i][j] = false;
			red.pop_back();
		}
		if (G > 0) {
			green.push_back(make_pair(i, j));
			check[i][j] = true;
			recursion(red, green, check, G - 1, R, i1 + 1, v);
			check[i][j] = false;
			green.pop_back();
		}


	}
}
int main() {
	
	cin >> N >> M >> G >> R;
	vector <pair <int, int>> garrrden;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &garden[i][j]);
			if (garden[i][j] == 2) {
				garrrden.push_back(make_pair(i, j));
			}
		}
	}
	vector <pair <int, int>> red;
	vector <pair <int, int>> green;

	bool check[51][51] = { false, };
	recursion(red, green, check, G, R, 0, garrrden);
	cout << result;
	//system("Pause");

}
