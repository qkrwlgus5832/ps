#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int number[10][13][2] = {
	{{0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,2},{3,0},{3,2},{4,0},{4,1},{4,2}},
	{{0,0},{1,0},{2,0},{3,0},{4,0}},
	{{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,0},{4,0},{4,1},{4,2}},
	{{0,0}, {0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,2},{4,2},{4,1},{4,0}},
	{{0,0},{1,0},{2,0},{2,1},{2,2},{1,2},{0,2},{3,2},{4,2}},
	{{0,0}, {0,1},{0,2},{1,0},{2,0},{2,1},{2,2},{3,2},{4,2},{4,1},{4,0}},
	{{0,0},{0,1},{0,2},{1,0},{2,0},{2,1},{2,2},{3,0},{4,0},{3,2},{4,2},{4,1}},
	{{0,0},{0,1},{0,2},{1,2},{2,2},{3,2},{4,2}},
	{{0,0}, {0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,2},{4,2},{4,1},{4,0}, {1,0}, {3,0}},
	{{0,0}, {0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,2},{4,2},{4,1},{4,0}, {1,0}}
};

int numberCount[10] = {12, 5, 11, 11, 9, 11, 12, 7, 13, 12 };
int graph[5][20001];
int N;
bool check_[5][20001];

bool check(int i, int j, int n) {
	for (int i1 = 0; i1 < 13; i1++) {
		int ni = i + number[n][i1][0];
		int nj = j + number[n][i1][1];

		if (ni < 0 || ni >= 5 || nj < 0 || nj >= N/5) {
			return false;
		}
		if (graph[ni][nj] == '.')
			return false;

		check_[ni][nj] = true;
	}
	return true;
}


int checkNumber(int i, int j) {
	vector <int> candidate;

	for (int n = 9; n >=0; n--) {
		if (check(i, j, n)) {
			candidate.push_back(n);
		}
	}

	if (candidate.size() ==0)
		return -1;

	int current;
	int maxCount = 0;
	for (int i = 0; i < candidate.size(); i++) {
		if (numberCount[candidate[i]] > maxCount) {
			current = candidate[i];
			maxCount = numberCount[candidate[i]];
		}
	}
	return current;
}

int main() {

	cin >> N;

	char tmp;

	scanf("%c", &tmp);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N/5; j++) {
			scanf("%c", &tmp);
			graph[i][j] = tmp;
		}
	}
	string result = "";

	for (int j = 0; j < N / 5; j++) {
		if (graph[0][j] == '#' && check_[0][j] == false) {
			int number = checkNumber(0, j);
			if (number != -1) {
				result += '0' + number;
			}
		}
	}

	cout << result;
	//system("Pause");
}
