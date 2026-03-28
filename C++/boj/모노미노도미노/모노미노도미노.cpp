#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int originMap[6][4];
int reversedMap[6][4];

int result = 0;

vector <pair <int, int>> direction[3] = {
	{{0,0}, {0,0}},{{0,0},{0,1}},{{0,0},{1,0}}
};

int isScore(int map[6][4]) {
	int score = 0;
	for (int i = 0; i < 6; i++) {
		int count = 0;
		for (int j = 0; j < 4; j++) {
			if (map[i][j] == 0) {
				break;
			}
			count++;
		}
		if (count == 4) {
			score++;
			for (int j = 0; j < 4; j++) {
				map[i][j] = 0;
			}
		}

	}
	return score;
}

void down(int map[6][4], vector <pair <int, int>> &v, int number) {
	int lastIndex = 5;
	bool flag = false;
	for (int i = v[0].first + 1; i < 6; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (map[i][v[j].second] > 0) {
				lastIndex = i - 1;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	for (int j = 0; j < v.size(); j++) {
		map[lastIndex][v[j].second] = number;
	}
}
void move(int map[6][4]) {
	int tmpMap[6][4] = { 0, };

	memcpy(tmpMap, map, sizeof(tmpMap));
	memset(map, 0, sizeof(tmpMap));

	int count = 0;

	for (int i = 5; i >= 0; i--) {
		vector <pair <int, int>> v;
		bool check[4] = { false, };
		for (int j = 0; j < 4; j++) {
			if (tmpMap[i][j] > 0 && check[j] == false) {
				v.push_back({ i,j });
				for (int j1 = j + 1; j1 < 4; j1++) {
					if (tmpMap[i][j] == tmpMap[i][j1]) {
						check[j1] = true;
						v.push_back({ i,j1 });
					}
					else {
						break;
					}
				}
				down(map, v, tmpMap[i][j]);
				v.clear();
			}

		}

	}

}

bool check(int map[6][4]) {
	int count = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] > 0) {
				count++;
				break;
			}
		}
	}
	if (count > 0) {
		for (int i = 5; count > 0; count--, i--) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = 0;
			}

		}
		return true;
	}
	return false;
}

void insert(int location, int dir, int map[6][4], int number) {
	int lastIndex = 0;

	for (int i = 0; i < 6; i++) {

		int ni = i + dir[direction][0].first;
		int nj = location + dir[direction][0].second;
		int ni2 = i + dir[direction][1].first;
		int nj2 = location + dir[direction][1].second;

		if (ni < 0 || nj < 0 || ni >= 6 || nj >= 4 || ni2 < 0 || nj2 < 0 || ni2 >= 6 || nj2 >= 4)
			continue;
		if (map[ni][nj] == 0 && map[ni2][nj2] == 0)
			lastIndex = i;
		else {
			break;
		}
	}
	int ni = lastIndex + dir[direction][0].first;
	int nj = location + dir[direction][0].second;
	int ni2 = lastIndex + dir[direction][1].first;
	int nj2 = location + dir[direction][1].second;

	map[ni][nj] = number; map[ni2][nj2] = number;
}
void simulation(int t, int x, int y, int number) {

	if (t == 0) {
		insert(y, 0, originMap, number);
		insert(x, 0, reversedMap, number);
	}
	else if (t == 1) {
		insert(y, 1, originMap, number);
		insert(x, 2, reversedMap, number);
	}
	else {
		insert(y, 2, originMap, number);
		insert(x, 1, reversedMap, number);
	}

	while (1) { // 점수를 얻을 수 있을 때 까지 얻고
		int score = isScore(originMap);
		if (score == 0)
			break;
		result += score;
		move(originMap);
	}
	while (1) {
		int score = isScore(reversedMap);

		if (score == 0)
			break;
		result += score;
		move(reversedMap);
	}

	if (check(originMap) > 0) { //연한 칸에 블록이 있는지 check
		move(originMap);
	}

	if (check(reversedMap) > 0) {
		move(reversedMap);
	}
}
int main() {
	int N;
	cin >> N;

	int t, x, y;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &t, &x, &y);
		simulation(t - 1, x, y, i + 1);
	}

	cout << result << endl;

	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			count += (originMap[i][j] > 0 ? 1 : 0);
			count += (reversedMap[i][j] > 0 ? 1 : 0);
		}
	}
	cout << count;
	//system("Pause");
}
