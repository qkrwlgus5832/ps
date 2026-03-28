#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


char graph[21][21];

class cleaner {
public:
	int x;
	int y;
	int bitmask;

	cleaner(int x, int y, int bitmask) {
		this->x = x;
		this->y = y;
		this->bitmask = bitmask;
	}
};

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int BFS(int w, int h, int count, map <pair <int, int>, int>& m) {
	bool check[21][21][2050] = { false, };
	queue <cleaner> q;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (graph[i][j] == 'o') {
				q.push(cleaner(i, j, 0));
				check[i][j][0] = true;
				break;
			}
		}
	}

	int length = 0;

	while (q.size()) {
		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			cleaner front = q.front();
			q.pop();

			if (front.bitmask == pow(2, count) - 1) {
				return length;
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.x + dir[i1][0];
				int nj = front.y + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
					continue;
				}
				if (graph[ni][nj] == 'x') {
					continue;
				}
				int tmp = front.bitmask;

				if (graph[ni][nj] == '*') {
					int index = m[{ni, nj}];
					tmp = front.bitmask | (1 << index);
				}
				if (check[ni][nj][tmp] == false) {
					check[ni][nj][tmp] = true;
					q.push({ ni,nj, tmp });
				}
			}
		}
		length++;
	}
	return -1;
}

int main() {
	int w, h;

	while (1) {
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			scanf("%s", &graph[i]);
		}
		int count = 0;

		map <pair <int, int>, int> m;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] == '*') {
					m[{i, j}] = count;
					count++;
				}
			}
		}
		printf("%d\n", BFS(w, h, count, m));
	}
	//system("Pause");
}
