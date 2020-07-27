#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int chess[1001][1001];
int n, m;

void input(vector <pair <int, int>> &v) {
	int count;
	cin >> count;

	int x, y;
	for (int i = 0; i < count; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x,y });
		chess[x][y] = 2;
	}
}


void queenCheck(vector <pair <int, int>> &queen) {
	int dir[8][2] = { {-1,0}, {1,0}, {0,-1}, {0,1},{1, -1}, {-1,1}, {-1,-1}, {1,1} };
	for (auto location : queen) {
		for (int i = 0; i < 8; i++) {
			int length = 1;
			while (1) {
				int ni = location.first + dir[i][0] * length;
				int nj = location.second + dir[i][1] * length;

				if (ni < 1 || nj < 1 || ni > n || nj > m || chess[ni][nj] == 2)
					break;

				chess[ni][nj] = 1;
				length++;
			}
		}
	}
}

void knightCheck(vector <pair <int, int>> &knight) {
	int dir[8][2] = { {-1, -2}, {-2,-1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2,1}, {1,2} };

	for (auto location : knight) {
		for (int i = 0; i < 8; i++) {
			int ni = location.first + dir[i][0];
			int nj = location.second + dir[i][1];

			if (ni < 1 || nj <1 || ni> n || nj >m)
				continue;

			chess[ni][nj] = 1;
		}
	}
}
int solution(const vector <vector <pair <int ,int>>>  &v) {
	vector <pair <int, int>> queen = v[0];
	vector <pair <int, int>> knight = v[1];

	queenCheck(queen);
	knightCheck(knight);

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chess[i][j] == 0)
				result++;
		}
	}
	return result;
}

int main() {

	cin >> n >> m;

	int q;
	vector <pair <int, int>> queen;
	input(queen);
	vector <pair <int, int>> knight;
	input(knight);
	vector <pair <int, int>> pawn;
	input(pawn);

	cout << solution({ queen, knight, pawn });

	//system("Pause");
}
