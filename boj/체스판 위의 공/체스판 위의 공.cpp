#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

pair <int, int> dp[501][501];

int R, C;
int graph[501][501];
int answer[501][501];
bool check[501][501];
bool pathCheck[501][501];

void checkAnswer(pair <int ,int> current, pair <int ,int> location) {
	check[current.first][current.second] = true;
	dp[current.first][current.second] = location;
	answer[location.first][location.second]++;
}

 const pair <int ,int> recursion(const pair <int ,int> current) {
	pair <int, int> minLocation = current;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0)
				continue;
			int ni = current.first + i;
			int nj = current.second + j;

			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;

			if (pathCheck[ni][nj])
				continue;
			
			if (graph[current.first][current.second] > graph[ni][nj]) {
				if (graph[ni][nj] < graph[minLocation.first][minLocation.second]) {
					minLocation.first = ni; minLocation.second = nj;
				}
			}
		}
	}

	if (minLocation == current) {
		checkAnswer(current, current);
		return current;
	}
	else if (check[minLocation.first][minLocation.second]) {
		pair <int, int> location = dp[minLocation.first][minLocation.second];
		checkAnswer(current, location);
		return location;
	}
	else {
		pathCheck[minLocation.first][minLocation.second] = true;
		pair <int, int> location = recursion(minLocation);

		pathCheck[minLocation.first][minLocation.second] = false;
		check[current.first][current.second] = true;
		dp[current.first][current.second] = location;

		return location;
	}

	return { -1,-1 };
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			pathCheck[i][j] = true;
			recursion({ i,j });
			pathCheck[i][j] = false;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
	//system("Pause");
}