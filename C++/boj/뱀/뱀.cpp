#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>

using namespace std;

map <char, int> m;

int dir[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0,1} };

int curvedDir[4][2] = { {2,3}, {3,2}, {1,0}, {0,1} };

char direction[4] = { 'u', 'd', 'l', 'r' };

deque <pair <int,int>> q;

bool graph[101][101];
bool check[101][101];

queue <pair <int, char>> rotation;
int N;

char changeDireciton(int dirIndex, char curve) {
	if (curve == 'L')
		return direction[curvedDir[dirIndex][0]];
	return direction[curvedDir[dirIndex][1]];
}

int gaming(char currentdir, int time) {
	while (1) {
		time++;
		int dirIndex = m[currentdir];
		int ni = q.front().first + dir[dirIndex][0];
		int nj = q.front().second + dir[dirIndex][1];


		if (ni <0 || nj <0 || ni >= N || nj >=N || check[ni][nj] == true) {
			return time;
		}

		check[ni][nj] = true;

		q.push_front(make_pair(ni, nj));

		if (graph[ni][nj] == false) {
			check[q.back().first][q.back().second] = false;
			q.pop_back();
		}
		else {
			graph[ni][nj] = false;
		}

		if (rotation.size() && rotation.front().first == time) {
			currentdir = changeDireciton(dirIndex, rotation.front().second);
			rotation.pop();
		}
	}
}
int main() {
	
	cin >> N;

	int K;
	cin >> K;
	int x, y;

	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		graph[x-1][y-1] = true;
	}
	int L;
	int X;
	char C;
	cin >> L;


	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		rotation.push(make_pair(X, C));
	}
	q.push_back(make_pair(0, 0));
	m.insert(make_pair('u', 0));
	m.insert(make_pair('d', 1));
	m.insert(make_pair('l', 2));
	m.insert(make_pair('r', 3));
	cout << gaming('r', 0);
	system("Pause");
}