#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
	
char graph[51][51];
bool check[51][51][4][10];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
map <pair <int, int>, int> m;

class node {
public:
	int x;
	int y;
	int bitmask;
	int direction;

	node(int x, int y, int bitmask, int direction) {
		this->x = x;
		this->y = y;
		this->bitmask = bitmask;
		this->direction = direction;
	}
};

int BFS(pair <int, int> start) {
	queue <node> q;
	q.push(node(start.first, start.second, false, -1));
	//check[start.first][start.second][0] = true;

	int time = 0;


	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			node front = q.front();
		
			q.pop();

	
			for (int i1 = 0; i1 < 4; i1++) {
				if (i1 == front.direction) {
					continue;
				}
				int ni = front.x + dir[i1][0];
				int nj = front.y + dir[i1][1];

				if (front.bitmask == 3) {
					return time;

				}
				if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
					continue;
				}

				int tmpBitmask = front.bitmask;

				if (graph[ni][nj] == 'C') {
					tmpBitmask = tmpBitmask | (1 << m[{ni, nj}]);
				}

				if (graph[ni][nj] != '#' && check[front.x][front.y][i1][tmpBitmask] == false) {
					check[front.x][front.y][i1][tmpBitmask] = true;
					q.push({ ni,nj, tmpBitmask, i1 });
					
				}

			}
		}
		time++;
	}
	return -1;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		scanf("%s", &graph[i]);
	}

	pair <int, int> start;

	int index = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {		
			if (graph[i][j] == 'C') {
				m[{i, j}] = index++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 'S') {
				printf("%d", BFS({ i,j }));
				break;
			}
		}
	}
	//system("Pause");
}
