#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

int notebook[41][41];

void setiingZero(int sticker[11][11]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			sticker[i][j] = 0;
		}
	}
}
void rotate(int sticker[11][11], int& R, int& C) {
	int tmp[11][11];
	memcpy(tmp, sticker, sizeof(tmp));
	setiingZero(sticker);

	for (int j = 0; j < C; j++) {
		vector <int> v;
		for (int i = R - 1; i >= 0; i--) {
			v.push_back(tmp[i][j]);
		}
		for (int i = 0; i < R; i++) {
			sticker[j][i] = v[i];
		}
	}
	swap(R, C);
}

bool IfCan(int sticker[11][11], int R, int C) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
		
			bool flag = false;

			for (int i1 = 0; i1 < R; i1++) {
				for (int j1 = 0; j1 < C; j1++) {
					if (i + i1 >= N || j + j1 >= M) {
						flag = true;
					}
					else if (sticker[i1][j1] == 1 && notebook[i + i1][j + j1] == 1) {
						flag = true;						
					}
			
				}
			}

			if (flag == false) {
				for (int i1 = 0; i1 < R; i1++) {
					for (int j1 = 0; j1 < C; j1++) {
						if (sticker[i1][j1] == 1) {
							notebook[i + i1][j + j1] = 1;

						}
					}
				}
				return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < K; i++) {
		int sticker[11][11] = { 0, };
		int R, C;
		scanf("%d %d", &R, &C);

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				scanf("%d", &sticker[r][c]);
				
			}
		}
		for (int i = 0; i < 4; i++) {
			if (IfCan(sticker, R, C) == false) {
				rotate(sticker, R, C);
			}
			else
				break;
		}

	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (notebook[i][j] == 1) {
				result++;
			}
		}
	}
	cout << result;
	//system("Pause");
}