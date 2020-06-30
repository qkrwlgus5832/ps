#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;

int N, L;


int graph[101][101];
bool check[101][101];

int result = 0;

int dir[4][2] = { { 0 ,-1 }, {0,1},{-1,0},{1,0} };

bool recursion(int i, int j, int height, int count, int direction) {
	if (check[i][j] == true) {
		return false;
	} 
	check[i][j] = true;
	if (count == L)
		return true;

	int ni = i + dir[direction][0];
	int nj = j + dir[direction][1];

	if (ni < 0 || nj < 0 || ni >= N || nj >= N)
		return false;

	if (check[ni][nj] == false && graph[ni][nj] == height) {
		return recursion(ni, nj, height, count + 1, direction);
	}
	else {
		return false;
	}


}

bool checkHeight(int i, int j, int i1, int j1) {
	if ((graph[i][j] < graph[i1][j1]) && (graph[i1][j1] - graph[i][j] == 1))
		return true;
	return false;

}
void rowcheck() {
	for (int i = 0; i < N; i++) {
		bool flag = false;
		bool isAnswer = true;
		for (int j = 0; j < N - 1; j++) {
			if (graph[i][j] != graph[i][j + 1]) {
				if (checkHeight(i,j,i,j+1)== true) {
					isAnswer = isAnswer &&  recursion(i, j, graph[i][j], 1, 0);
				}
				else if (checkHeight(i, j+1, i, j) == true){
					isAnswer = isAnswer && recursion(i, j + 1, graph[i][j + 1], 1, 1);
				}
				else {
					flag = true; isAnswer = false;
					break;
				}
				flag = true;
			}
		}
		if (flag == false)
			result++;
		else if (isAnswer)
			result++;
	}
}

void colcheck() {
	for (int j = 0; j < N ; j++) {
		bool flag = false;
		bool isAnswer = true;
		for (int i = 0; i < N - 1; i++) {
			if (graph[i][j] != graph[i+ 1][j]) {
				if (checkHeight(i, j, i+1, j)) {
					isAnswer = isAnswer && recursion(i, j, graph[i][j], 1, 2);
				}
				else if (checkHeight(i+1, j, i , j)){
					isAnswer = isAnswer && recursion(i+1 , j, graph[i + 1][j], 1, 3);
				}
				else {
					flag = true;
					isAnswer = false;
					break;
				}
				flag = true;
			}
		}
		if (flag == false)
			result++;
		else if (isAnswer)
			result++;
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	rowcheck();
	memset(check, false, sizeof(check));
	colcheck();
	cout << result;
	//system("Pause");
}