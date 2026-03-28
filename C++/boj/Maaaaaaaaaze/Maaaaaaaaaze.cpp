#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <time.h>

using namespace std;

int graph[5][5][5];

vector <vector <int>> A;

int result = INT_MAX;

int rotatedgraph[5][5][5][5];

int dir[6][3] = {
	{-1,0,0},
	{1,0,0},
	{0,1,0},
	{0,-1,0},
	{0,0,-1},
	{0,0,1}
};

int dirSize[5] = { 4,4,4,4,4 };

class node {
public:
	int z;
	int x;
	int y;

	node(int z, int x, int y) {
		this->z = z;
		this->x = x;
		this->y = y;
	}
};


int BFS(int maze[5][5][5], int z, int x ,int y) {
	bool check[5][5][5] = { false, };

	queue <node> q;
	check[z][x][y] = true;

	if (maze[z][x][y] == 1) {
		q.push(node(z, x, y));
	}

	int level = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			node front = q.front();
			q.pop();

			if ((front.x == 0 || front.x == 4) && (front.y == 0 || front.y == 4) && (front.z == 0 || front.z == 4)) {
				if (front.z != z && front.x != x && front.y != y) {
					result =min(result, level);
					return level;
				}
			}

			for (int i = 0; i < 6; i++) {
				int nz = front.z + dir[i][0];
				int nx = front.x + dir[i][1];
				int ny = front.y + dir[i][2];

				if (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
					continue;
				if (maze[nz][nx][ny] == 0)
					continue;
				if (check[nz][nx][ny] == true)
					continue;

				check[nz][nx][ny] = true;

				
				q.push(node(nz, nx, ny));
			}
		}
		level++;
	}
	
	return INT_MAX;
}

void initZero(int graph[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			graph[i][j] = 0;
		}
	}
}
void rotate(int graph[5][5]) {

	int tmpgraph[5][5];
	memcpy(tmpgraph, graph, sizeof(tmpgraph));
	initZero(graph);

	for (int j = 0; j < 5; j++) {
		vector <int> v;
		for (int i = 4; i >=0; i--) {
			v.push_back(tmpgraph[i][j]);
		}
		for (int i = 0; i < 5; i++) {
			graph[j][i] = v[i];
		}
	}
}

bool ifSame(int graph1[5][5], int graph2[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (graph1[i][j] != graph2[i][j])
				return false;
		}
	}
	return true;
}
void init(int graph[5][5][5]) {


	for (int i = 0; i < 5; i++) {
		memcpy(rotatedgraph[0][i], graph[i], sizeof(graph[i]));
		for (int direction = 1; direction <= 3; direction++) {
			rotate(graph[i]);
			if (ifSame(rotatedgraph[direction - 1][i], graph[i])) {
				dirSize[i] = direction;
				break;
			}
			memcpy(rotatedgraph[direction][i], graph[i], sizeof(graph[i]));
		}
	}
}

void goBFS(vector <pair <int, int>> v) {
	int maze[5][5][5];

	for (int i = 0; i < v.size(); i++) {
		memcpy(maze[i], rotatedgraph[v[i].second][v[i].first], sizeof(maze[i]));
	}

	
	BFS(maze, 0, 0, 0);
	BFS(maze, 0, 0, 4);
	BFS(maze, 0, 4, 0);
	BFS(maze, 0, 4, 4);
	BFS(maze, 4, 0, 0);
	BFS(maze, 4, 0, 4);
	BFS(maze, 4, 4, 0);
	BFS(maze, 4, 4, 4);

}
void recursion(vector <pair <int, int>> v, bool check[5]) {

	if (v.size() == 5) {
		goBFS(v);
		if (result == 12) {
			cout << result;
			exit(0);
		}
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (check[i] == false) {
			for (int j = 0; j < dirSize[i]; j++) {
				v.push_back(make_pair(i, j));
				check[i] = true;
				recursion(v, check);
				check[i] = false;
				v.pop_back();
			}
		}
	}

}

int main() {


	for (int t = 0; t < 5; t++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", &graph[t][i][j]);
			}
		}
	}
	init(graph);

	vector <pair <int, int>> v;

	bool check[5] = { false, };
	recursion(v, check);

	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;


	//system("Pause");
}
