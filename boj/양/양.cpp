#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

char graph[251][251];
bool check[251][251];
int R, C;
int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };

void BFS(int i, int j, int& sheepCount, int& foxCount) {
	
	vector <pair <int,int>> sheep;
	vector <pair <int,int>> fox;

	check[i][j] = true;
	
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));

	if (graph[i][j] == 'o') {
		sheep.push_back(make_pair(i, j));
	}
	else if (graph[i][j] == 'v') {
		fox.push_back(make_pair(i, j));
	}
	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;
			if (check[ni][nj] || graph[ni][nj] == '#')
				continue;

			if (graph[ni][nj] == 'o') {
				sheep.push_back(make_pair(ni, nj));
			}
			else if (graph[ni][nj] == 'v') {
				fox.push_back(make_pair(ni, nj));
			}
			check[ni][nj] = true;
			q.push(make_pair(ni, nj));
		}
	}
	if (sheep.size() <= fox.size()) {
		sheepCount -= sheep.size();
		for (int i = 0; i < sheep.size(); i++) {
			graph[sheep[i].first][sheep[i].second] = '.';
		}
	}
	else {
		foxCount -= fox.size();
		for (int i = 0; i < fox.size(); i++) {
			graph[fox[i].first][fox[i].second] = '.';
		}
	}
}
int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		scanf("%s", graph[i]);
	}
	int sheepCount = 0;
	int foxCount = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 'o') {
				sheepCount++;
			}
			else if (graph[i][j] == 'v') {
				foxCount++;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check[i][j] == false && graph[i][j] != '#') {
				BFS(i, j, sheepCount, foxCount);
			}
		}
	}
	cout << sheepCount << " " << foxCount;
	//system("Pause");
}