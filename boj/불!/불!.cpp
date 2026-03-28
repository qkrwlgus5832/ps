#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int R, C;
char graph[1001][1001];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void fireBFS(queue <pair <int, int>>& fireQueue) {
	int s = fireQueue.size();

	for (int i = 0; i < s; i++) {
		pair <int, int> front = fireQueue.front();
		fireQueue.pop();
		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;

			if (graph[ni][nj] != '#' && graph[ni][nj] != 'F') {
				graph[ni][nj] = 'F';
				fireQueue.push({ ni,nj });
			}
		}
	}

}

int jihoonBFS(queue <pair <int, int>>& jihoonQueue) {
	int s = jihoonQueue.size();

	for (int i = 0; i < s; i++) {
		pair <int, int> front = jihoonQueue.front();
		jihoonQueue.pop();
		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				return -1;

			if (graph[ni][nj] != '#' && graph[ni][nj] != 'F' && graph[ni][nj] != 'J') {
				graph[ni][nj] = 'J';
				jihoonQueue.push({ ni,nj });
			}
		}
	}

	return jihoonQueue.size();
}

void init(queue <pair <int, int>>& fireQueue, queue <pair <int, int>>& jihoonQueue) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 'F') {
				fireQueue.push({ i,j });
			}
			else if (graph[i][j] == 'J') {
				jihoonQueue.push({ i,j });
			}
		}
	}

}
int simulation() {
	queue <pair <int, int>> fireQueue;
	queue <pair <int, int>> jihoonQueue;

	init(fireQueue, jihoonQueue);

	int time = 1;

	while (1) {
		fireBFS(fireQueue);
		int result = jihoonBFS(jihoonQueue);
		if (result == -1)
			return time;
		else if (result == 0)
			return -1;

		time++;
	}

}
int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		scanf("%s", &graph[i]);
	}
	
	int answer = simulation();
	if (answer == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << answer;
	}

	//system("Pause");
}
