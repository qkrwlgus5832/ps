#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

char origingraph[1501][1501];

int check[1501][1501];

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int meltingPoint[1501][1501];

int R, C;

vector<pair <int, int>> swanLocation;

bool BFS(int i, int j, int count, int day) {
	check[i][j] = count;
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int j = 0; j < 4; j++) {
			int ni = front.first + dir[j][0];
			int nj = front.second + dir[j][1];

			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;
			if ((meltingPoint[ni][nj] <= day || origingraph[ni][nj] == 'L') && check[ni][nj] != count) {
				check[ni][nj] = count;
				if (origingraph[ni][nj] == 'L')
					return true;
				q.push(make_pair(ni, nj));
			}
		}
	}
	return false;
}

bool checkIfAnswer(int count, int day) {
	return BFS(swanLocation[0].first, swanLocation[0].second, count, day);
}

int melting(queue <pair <int, int>> q) {
	int level = 1;
	while (q.size()) {
		int s = q.size();
		for (int i1 = 0; i1 < s; i1++) {
			pair <int, int> front = q.front();
			q.pop();

			bool flag = false;
			for (int i = 0; i < 4; i++) {
				int ni = front.first + dir[i][0];
				int nj = front.second + dir[i][1];

				if (ni < 0 || nj < 0 || ni >= R || nj >= C)
					continue;
				if ((origingraph[ni][nj] == '.' || origingraph[ni][nj] == 'L') && (meltingPoint[ni][nj] == 0 || meltingPoint[ni][nj] != level)) {
					meltingPoint[front.first][front.second] = level;
					origingraph[front.first][front.second] = '.';
					flag = true;
				}
			}
			if (flag == false)
				q.push(front);
			
		}
		level++;
	}
	return level;
}
int binary_search(int start, int end, int count) {
	if (start == end) {
		return start;
	}
	else if (start + 1 == end) {
		if (checkIfAnswer(count, start))
			return start;
		else
			return end;
	}

	if (checkIfAnswer(count, (start + end) / 2))
		return binary_search(start, (start + end) / 2, count + 1);
	else
		return binary_search((start + end) / 2 + 1, end, count + 1);
}

int main() {

	cin >> R >> C;

	char tmp;

	//int count = 0;
	queue <pair <int, int>> q;

	for (int i = 0; i < R; i++) {
		scanf("%c", &tmp);
		for (int j = 0; j < C; j++) {

			scanf("%c", &origingraph[i][j]);
			if (origingraph[i][j] == 'L') {
				swanLocation.push_back(make_pair(i, j));
				meltingPoint[i][j] = 0;
				//q.push(make_pair(i, j));
				//count++;
			}
			if (origingraph[i][j] == '.') {
				meltingPoint[i][j] = 0;
				//q.push(make_pair(i, j));
			}
			if (origingraph[i][j] == 'X') {
				q.push(make_pair(i, j));
			}
		}
	}
	int days = melting(q);
	cout << binary_search(0, days , 1);

	//system("Pause");
}