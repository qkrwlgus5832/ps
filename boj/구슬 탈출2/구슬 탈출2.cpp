#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>

using namespace std;

char graph[11][11];
int dir[4][2] = { {0,-1},{0, 1}, {-1,0}, {1,0} };

int result = -1;
int N, M;

class beed {
public:
	int x;
	int y;
	int success;

	beed(int x, int y, int success) {
		this->x = x;
		this->y = y;
		this->success = success;
	}
	beed() {}
};

beed hole;
beed red;
beed blue;

char checkFirst(int dirIndex, beed red, beed blue) {
	if (dirIndex == 0) {
		if (red.y < blue.y)
			return 'R';
	}
	else if (dirIndex == 1) {
		if (red.y > blue.y)
			return 'R';
	}
	else if (dirIndex == 2) {
		if (red.x < blue.x)
			return 'R';
	}
	else if (dirIndex == 3) {
		if (red.x > blue.x)
			return 'R';
	}
	return 'B';
}

int checkIfAnswer(pair <int, int> beed, char color) {
	if (beed.first == hole.x && beed.second == hole.y) {
		if (color == 'r')
			return 1;
		else
			return -1;
	}
	return 0;
}
beed dfs(int dirIndex, pair <beed, beed> beeds, char color) {
	bool flag = false;
	beed targetbeed = beeds.first;
	int ni = targetbeed.x+ dir[dirIndex][0];
	int nj = targetbeed.y + dir[dirIndex][1];
	if (!(ni < 0 || nj < 0 || ni >= N || nj >= M || graph[ni][nj] == '#')) {
		beed anotherbeed = beeds.second;


		int result = checkIfAnswer(make_pair(ni, nj), color);

		if (result == 0) {
			if (ni == anotherbeed.x && nj == anotherbeed.y)
				return beed(targetbeed.x, targetbeed.y, 0);
			targetbeed.x = ni;
			targetbeed.y = nj;
			beeds.first = targetbeed;
			return dfs(dirIndex, beeds, color);
		}


		return beed(ni, nj, result);
	}
	
	return beed(targetbeed.x, targetbeed.y, 0);
		
}
pair <bool, int> escape(vector <int> v, beed red, beed blue) {
	for (int i = 0; i < v.size(); i++) {
		int dirIndex = v[i];
		char firstbeed = checkFirst(dirIndex, red, blue);
		graph[red.x][red.y] = '.';
		graph[blue.x][blue.y] = '.';
		if (firstbeed == 'R') {
			red = dfs(dirIndex, make_pair(red, blue), 'r');
			blue = dfs(dirIndex, make_pair(blue, red), 'b');
		}

		else {
			blue = dfs(dirIndex, make_pair(blue, red), 'b');
			red = dfs(dirIndex, make_pair(red, blue), 'r');
		}
		graph[red.x][red.y] = 'R';
		graph[blue.x][blue.y] = 'B';
		if (red.success == 1 && blue.success != -1) {
			return make_pair(true, i + 1);
		}
		else if (blue.success == -1) {
			return make_pair(false, i + 1);
		}

	}
	return make_pair(false, -1);
}

void order(vector <int> v) {
	if (v.size() == 10) {

		pair <bool, int> tmp = escape(v, red, blue);
		if (tmp.first == true) {
			if (result == -1) {
				result = tmp.second;
			}
			else {
				result = min(result, tmp.second);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		order(v);
		v.pop_back();
	}
}

int main() {

	char tmp;
	int test;


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'R') {
				red.x = i; red.y = j;
			}
			else if (graph[i][j] == 'B') {
				blue.x = i; blue.y = j;
			}
			else if (graph[i][j] == 'O') {
				hole.x = i; hole.y = j;
			}
		}
	}

	vector <int> v;
	order(v);

	cout << result;

	//system("Pause");
}